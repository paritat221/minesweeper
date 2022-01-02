#include <stdlib.h>
#include <stdio.h>
#include <gint/rtc.h> 
#include <gint/display.h>
#include <gint/timer.h>
#include <gint/clock.h>
#include "board.h"

extern bopti_image_t img_cursor;

void set_board(struct Board *brd){
    int height = brd->height;
    int width = brd->width;

    brd->board_state = malloc(sizeof(struct Cell*) * height);
    for(int i=0; i<height; i++){
        brd->board_state[i] = malloc(sizeof(struct Cell) * width);
    }

    for(int v=0;v<height;v++){
        for(int z=0;z<width;z++){
            brd->board_state[v][z].value=0; //assign all cells 0 (no mine)
            brd->board_state[v][z].state=0;
            brd->board_state[v][z].flagged=0;
        }
    }
}

int around(int x, int y, int a, int b, struct Board* brd){
    int height = brd->height;
    int width = brd->width;
    for(int v=y-1;v<=y+1;v++){
        for(int z=x-1;z<=x+1;z++){
            if(z<width && v<height && z>=0 && v>=0){
                if(z==a && v==b)
                    return 1;
            }
        }
    }
    return 0;
}

void gen_board(int a, int b, struct Board *brd){
    int height = brd->height;
    int width = brd->width;

    for(int i=0; i<brd->nmines; i++){
        int y = rand()%brd->height;
        int x = rand()%brd->width;
        int limit=0;
        while(brd->board_state[y][x].value==69 || around(a,b,x,y,brd)){
            srand(rtc_ticks());
            y = rand()%brd->height;
            x = rand()%brd->width;
            limit++;
            if(limit>1000) break;
        }
        brd->board_state[y][x].value=69;

        for(int v=y-1;v<=y+1;v++){
            for(int z=x-1;z<=x+1;z++){
                if(z<width && v<height && z>=0 && v>=0){
                    if(brd->board_state[v][z].value!=69)
                        brd->board_state[v][z].value++;
                }
            }
        }
    }
}

void draw_board(struct Board *brd){
    extern bopti_image_t img_nums;
    extern bopti_image_t img_bomb;
    extern bopti_image_t img_desert_cell;
    extern bopti_image_t img_flag;
    int height = brd->height;
    int width = brd->width;

    for(int y=0; y<height; y++){
        for(int x=0; x<width;x++){
            
                if(brd->board_state[y][x].state){
                    int value = brd->board_state[y][x].value;
                    if(value==69){
                        dsubimage(x*20+10,y*20+10,&img_bomb,0,0,20,20, DIMAGE_NONE);
                    }else if(value==0){
                        dsubimage(x*20+10,y*20+10,&img_nums,160,0,180+20,20, DIMAGE_NONE);
                    }
                    else{
                        if(x*20<width*20)
                            dsubimage(x*20+10,y*20+10,&img_nums,(value-1)*20,0,value*20+20,20, DIMAGE_NONE);
                    }
                }else{
                    if(brd->board_state[y][x].flagged==1){
                        dsubimage(x*20+10,y*20+10,&img_flag,0,0,20,20, DIMAGE_NONE);
                    }else{
                        dsubimage(x*20+10,y*20+10,&img_desert_cell,0,0,20,20,DIMAGE_NONE);
                    }
                }
                if(brd->board_state[y][x].flagged==1)
                    dsubimage(x*20+10,y*20+10,&img_flag,0,0,20,20, DIMAGE_NONE);
        }
    }
    
}

void draw_cursor(struct Board *brd){
    dimage(brd->pos[0]*20+10,brd->pos[1]*20+10,&img_cursor);
}

void show_cell(int x,int y, struct Board *brd){
    int height = brd->height;
    int width = brd->width;
    if (x<width && y<height && x>=0 && y>=0 && brd->board_state[y][x].flagged==0) 
        brd->board_state[y][x].state=1;

    if (brd->board_state[y][x].value==0) { // invisible
        for (int v =y-1; v<=y+1;v++) {
            for (int z=x-1;z<=x+1;z++) {
                if (z<width && v<height && z>=0 && v>=0 && brd->board_state[y][x].flagged==0) {
                    if (brd->board_state[v][z].value != 69 && brd->board_state[v][z].state == 0) { // not mine and not visible and not flagged
                        show_cell(z,v,brd);
                    }
                }    
            }
        }
    }
}

void reveal(int x, int y, struct Board *brd){
    int height = brd->height;
    int width = brd->width;
    int flags = 0;
    for(int v=y-1;v<=y+1;v++){
        for(int z=x-1;z<=x+1;z++){
            if(z<width && v<height && z>=0 && v>=0){
                if(brd->board_state[v][z].flagged == 1)
                    flags++;
            }
        }
    }
    if(brd->board_state[y][x].value==flags && brd->board_state[y][x].value!=0){
        for(int v=y-1;v<=y+1;v++){
            for(int z=x-1;z<=x+1;z++){
                if(z<width && v<height && z>=0 && v>=0){
                    if(brd->board_state[v][z].flagged==0)
                        brd->board_state[v][z].state=1;
                }
            }
        }
        for(int v=y-1;v<=y+1;v++){
            for(int z=x-1;z<=x+1;z++){
                if(z<width && v<height && z>=0 && v>=0){
                    if(brd->board_state[v][z].state==1 && brd->board_state[v][z].value==0)
                        show_cell(z,v,brd);
                }
            }
        }
    }
}

void flag_cell(int x,int y, struct Board *brd){
    int height = brd->height;
    int width = brd->width;
    if (x<width && y<height && x>=0 && y>=0 && brd->board_state[y][x].state==0) 
        brd->board_state[y][x].flagged=!brd->board_state[y][x].flagged;
}

