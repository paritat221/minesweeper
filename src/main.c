#include <gint/display.h>
#include <gint/keyboard.h>
#include "board.h"

int main(void)
{
    extern bopti_image_t img_bugdenial;
	dclear(C_WHITE);
	dupdate();

	int key = 0;
    int hasgen = 0;

    struct Board *brd;
        brd->height = 9;
        brd->width = 13;
        brd->nmines = 14;
        brd->pos[0] = 5;
        brd->pos[1] = 5;

    set_board(brd);
    
    int trollface = 0;
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
        else if(key == 0x15 || key == 0x81){ //shift or exe
            if(!hasgen){
                gen_board(brd->pos[0],brd->pos[1],brd);
                hasgen = 1;
            }
            show_cell(brd->pos[0],brd->pos[1],brd);
            reveal(brd->pos[0],brd->pos[1],brd);
        }
        
        draw_cursor(brd);      
    }

	return 1;
}