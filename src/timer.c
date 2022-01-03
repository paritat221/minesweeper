#include <stdlib.h>
#include <stdio.h>
#include <gint/rtc.h> 
#include <gint/display.h>
#include <gint/timer.h>
#include <gint/clock.h>
#include "timer.h"
#include "board.h"

void draw_timer(int seconds, struct Board *brd){
    extern bopti_image_t img_digits;
    extern bopti_image_t img_minus;
    int digits[3];
    int i=2;
    if(seconds>999)seconds=999;
    while(i>=0){
        digits[i] = seconds % 10;  
        seconds = seconds/10;
        i--;
    }
    dsubimage(40, 7, &img_digits, 154, 0, 159, 27, DIMAGE_NONE);
    if(digits[0]==0)
        dsubimage(45, 7, &img_digits, 126, 0, 140, 27, DIMAGE_NONE);
    else 
        dsubimage(45, 7, &img_digits, 14*(digits[0]-1), 0, 14*digits[0], 27, DIMAGE_NONE);
    if(digits[1]==0)
        dsubimage(45+14, 7, &img_digits, 126, 0, 140, 27, DIMAGE_NONE);
    else 
        dsubimage(45+14, 7, &img_digits, 14*(digits[1]-1), 0, 14*digits[1], 27, DIMAGE_NONE);

    if(digits[2]==0)
        dsubimage(45+28, 7, &img_digits, 126, 0, 140, 27, DIMAGE_NONE);
    else 
        dsubimage(45+28, 7, &img_digits, 14*(digits[2]-1), 0, 14*digits[2], 27, DIMAGE_NONE);

    dsubimage(45+42, 7, &img_digits, 161, 0, 164, 27, DIMAGE_NONE);

    /* flags */

    dsubimage(320, 7, &img_digits, 154, 0, 159, 27, DIMAGE_NONE);

        
    int height = brd->height;
    int width = brd->width;
    int flags = 0;
    for(int y=0; y<height; y++){
        for(int x=0; x<width;x++){
            if(brd->board_state[y][x].flagged)
                flags++;
        }
    }
    flags = brd->nmines - flags;
    int negative = flags < 0;
    
    if(!negative){
        int digits[3];
        int i=2;
        while(i>=0){
            digits[i] = flags % 10;  
            flags = flags/10;
            i--;
        }
        dsubimage(320, 7, &img_digits, 154, 0, 159, 27, DIMAGE_NONE);
        if(digits[0]==0)
            dsubimage(325, 7, &img_digits, 126, 0, 140, 27, DIMAGE_NONE);
        else 
            dsubimage(325, 7, &img_digits, 14*(digits[0]-1), 0, 14*digits[0], 27, DIMAGE_NONE);
        if(digits[1]==0)
            dsubimage(325+14, 7, &img_digits, 126, 0, 140, 27, DIMAGE_NONE);
        else 
            dsubimage(325+14, 7, &img_digits, 14*(digits[1]-1), 0, 14*digits[1], 27, DIMAGE_NONE);

        if(digits[2]==0)
            dsubimage(325+28, 7, &img_digits, 126, 0, 140, 27, DIMAGE_NONE);
        else 
            dsubimage(325+28, 7, &img_digits, 14*(digits[2]-1), 0, 14*digits[2], 27, DIMAGE_NONE);
    }else{
        int num = flags + (flags*-1) + (flags*-1);
        if(num>99)num=99;
        int digits[3];
        int i=2;
        while(i>=0){
            digits[i] = num % 10;  
            num = num/10;
            i--;
        }
        dsubimage(320, 7, &img_digits, 154, 0, 159, 27, DIMAGE_NONE);
        if(digits[0]==0)
            dsubimage(325, 7, &img_digits, 126, 0, 140, 27, DIMAGE_NONE);
        else 
            dsubimage(325, 7, &img_digits, 14*(digits[0]-1), 0, 14*digits[0], 27, DIMAGE_NONE);
        if(digits[1]==0)
            dsubimage(325+14, 7, &img_digits, 126, 0, 140, 27, DIMAGE_NONE);
        else 
            dsubimage(325+14, 7, &img_digits, 14*(digits[1]-1), 0, 14*digits[1], 27, DIMAGE_NONE);

        if(digits[2]==0)
            dsubimage(325+28, 7, &img_digits, 126, 0, 140, 27, DIMAGE_NONE);
        else 
            dsubimage(325+28, 7, &img_digits, 14*(digits[2]-1), 0, 14*digits[2], 27, DIMAGE_NONE);

       dimage(325,7,&img_minus);
    }
    dsubimage(325+42, 7, &img_digits, 161, 0, 164, 27, DIMAGE_NONE);

}

