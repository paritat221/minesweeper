#include <gint/display.h>
#include <gint/keyboard.h>
#include "board.h"

int main(void)
{
    extern bopti_image_t img_bugdenial;
	dclear(C_WHITE);
	dupdate();
    int key = 0;
    while(key!=KEY_MENU){
        key = 0;
        int hasgen = 0;

        struct Board *brd;
            brd->height = 9;
            brd->width = 13;
            brd->nmines = 14;
            brd->pos[0] = 5;
            brd->pos[1] = 5;

        set_board(brd);
        dclear(C_WHITE);
        draw_board(brd);
        dimage(brd->width*20+10,10,&img_bugdenial);

        int trollface = 0;
        int trollfaced[2] = {5,5};
            
        while(!trollface){
            dclear(C_WHITE);
            draw_board(brd);
            dimage(brd->width*20+10,10,&img_bugdenial);
            draw_cursor(brd);
            dupdate();
            key = getkey_opt(GETKEY_DEFAULT & ~GETKEY_MOD_SHIFT & ~GETKEY_MOD_ALPHA, NULL).key;

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
                int rvl = reveal(brd->pos[0],brd->pos[1],brd);
                if(rvl == 1){
                    trollface = 1;
                    trollfaced[0] = brd->pos[0];
                    trollfaced[1] = brd->pos[1];
                    break;
                }
            }
            
            draw_cursor(brd);      
        }
        while(trollface == 1){
            dclear(C_WHITE);
            lose(trollfaced[0],trollfaced[1], brd);
            dimage(brd->width*20+10,10,&img_bugdenial);
            dupdate();
            key = getkey_opt(GETKEY_DEFAULT & ~GETKEY_MOD_SHIFT & ~GETKEY_MOD_ALPHA, NULL).key;

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