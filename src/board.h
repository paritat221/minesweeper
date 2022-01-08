#ifndef _PRINCEOFMYNES_BOARD_H
#define _PRINCEOFMYNES_BOARD_H

#include <gint/display.h>
#include <gint/timer.h>
#include <gint/clock.h>

struct Cell{
    int value; /*69 for a mine*/
    int state; /* 0-> not shown, 1-> shown*/
    int flagged; /* 0-> not flagged, 1-> flagged*/
};

struct Board{
    int height; /*in cells*/
    int width;  /*in cells*/
    int nmines;
    int pos[2]; /*[0]->pos x, [1]->pos y*/
    struct Cell **board_state; 
};

void gen_board(int, int, struct Board*);
void draw_board(struct Board*);
void draw_cursor(struct Board*);
int show_cell(int ,int, struct Board*);
void flag_cell(int ,int, struct Board*);
int reveal(int ,int, struct Board*, int*);
void set_board(struct Board*);
void lose(int, int, struct Board*);
int won(struct Board*);
int around(int, int, int, int, struct Board*);


#endif