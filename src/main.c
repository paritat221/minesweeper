#include <gint/display.h>
#include <gint/keyboard.h>
#include <gint/timer.h>
#include <gint/clock.h>
#include "board.h"
#include "timer.h"

#define SHIFT 1
#define OPTN 2
#define ALPHA 3
#define DIR_UP 4
#define DIR_DOWN 5
#define DIR_LEFT 6
#define DIR_RIGHT 7
#define ENGINE_TICK 25

static int callback_tick(volatile int *tick)
{
    *tick = 1;
    return TIMER_CONTINUE;
}

static int get_inputs(void)
{
    int opt = GETKEY_DEFAULT & ~GETKEY_REP_ARROWS & ~GETKEY_MOD_SHIFT & ~GETKEY_MOD_ALPHA;
    int timeout = 1;

    while(1)
    {
        key_event_t ev = getkey_opt(opt, &timeout);
        if(ev.type == KEYEV_NONE) return -1;

        //int key = ev.key;
        // if(key == KEY_SHIFT)  
        //     return KEY_SHIFT;
        // if(key == KEY_OPTN)  
        //     return KEY_OPTN;
        // if(key == KEY_ALPHA)
        //     return KEY_ALPHA;  
        // if(key == KEY_DOWN)  
        //     return KEY_DOWN;
        // if(key == KEY_RIGHT) 
        //     return KEY_RIGHT;
        // if(key == KEY_UP)    
        //     return KEY_UP;
        // if(key == KEY_LEFT)  
        //     return KEY_LEFT;
        return ev.key;
    }
}

int main(void)
{
    extern bopti_image_t img_bugdenial;
    extern bopti_image_t img_alive;
    extern bopti_image_t img_dead;
	dclear(C_WHITE);
	dupdate();
    int key = 0;
    while(key!=KEY_MENU){
        key = 0;
        int hasgen = 0;
        struct Board board;
            board.height = 9;
            board.width = 19;
            board.nmines = 21;
            board.pos[0] = 5;
            board.pos[1] = 5;
        struct Board *brd = &board;
        set_board(brd);
        dclear(C_WHITE);
        draw_board(brd);
        dimage(brd->width*20+7,10,&img_bugdenial);
        int trollface = 0;
        int trollfaced[2] = {5,5};
        static volatile int tick = 1;
        int t = timer_configure(TIMER_ANY, ENGINE_TICK*1000, GINT_CALL(callback_tick, &tick));
        if(t >= 0) timer_start(t);

        int s_time = 0;
        float f_time = 0;
        while(trollface == 0){
            while(!tick) sleep();
            tick = 0;
            f_time += 25;
            s_time = (int)(f_time/1000);
            dclear(C_WHITE);
            int win = won(brd);
            if(win==1){
                trollface=2;
            }
            draw_board(brd);
            dimage(brd->width*20+7,10,&img_bugdenial);
            draw_cursor(brd);
            draw_timer(s_time, brd);
            dimage(182, 10, &img_alive);
            dupdate();
            key = get_inputs();
            
            if(key==KEY_DOWN && brd->pos[1]<brd->height-1)
                brd->pos[1]++;
            else if(key==KEY_UP && brd->pos[1]>0)
                brd->pos[1]--;
            else if(key==KEY_RIGHT && brd->pos[0]<brd->width-1)
                brd->pos[0]++;
            else if(key==KEY_LEFT && brd->pos[0]>0)
                brd->pos[0]--;
            else if(key == 0x71)
                flag_cell(brd->pos[0],brd->pos[1],brd);
            else if(key == 0x81){ //shift or exe
                if(!hasgen){
                    gen_board(brd->pos[0],brd->pos[1],brd);
                    hasgen = 1;
                }
                struct Cell cell = brd->board_state[brd->pos[1]][brd->pos[0]];
                if(cell.value==69 && cell.flagged==0){
                    trollface = 1;
                    trollfaced[0] = brd->pos[0];
                    trollfaced[1] = brd->pos[1];
                    break;
                }
                show_cell(brd->pos[0],brd->pos[1],brd);
                int rvl[2];
                int rvl_state = reveal(brd->pos[0],brd->pos[1],brd,rvl);
                if(rvl_state==1){
                    trollface = 1;
                    trollfaced[0] = rvl[0];
                    trollfaced[1] = rvl[1];
                    break;
                }
            }
            draw_cursor(brd); 
        }
        while(trollface == 1){
            while(!tick) sleep();
            tick = 0;
            dclear(C_WHITE);
            lose(trollfaced[0],trollfaced[1], brd);
            dimage(brd->width*20+7,10,&img_bugdenial);
            draw_timer(s_time, brd);
            dimage(182, 10, &img_dead);
            dupdate();
            key = get_inputs();

            if(key == KEY_OPTN){
                trollface = 0;
                trollfaced[0] = 5;
                trollfaced[1] = 5;
                hasgen = 0;
            }
        }
        while(trollface == 2){
            while(!tick) sleep();
            tick = 0;
            dclear(C_WHITE);
            draw_board(brd);
            dimage(brd->width*20+7,10,&img_bugdenial);
            draw_timer(s_time, brd);
            dimage(182, 10, &img_alive);
            dupdate();
            key = get_inputs();

            if(key == KEY_OPTN){
                trollface = 0;
                trollfaced[0] = 5;
                trollfaced[1] = 5;
                hasgen = 0;
            }
        }
    }

	return 1;
}

