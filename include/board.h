#ifndef BOARD_H
#define BOARD_H

#include "tetromino.h"

void init_game();
void draw_board();
int check_collision(int x, int y, Tetromino *tetromino);
void place_tetromino(int x, int y, Tetromino *tetromino);
void drop_tetromino(float delta_time); 
void handle_input(float delta_time);   

float drop_interval; 
float drop_timer;    

#endif 
