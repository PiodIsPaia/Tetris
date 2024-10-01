#include <stdio.h>
#include <unistd.h> 
#include "board.h"

int main()
{
    init_game();
    float delta_time = 0.10; 
    while (1)
    {
        draw_board();     
        handle_input(delta_time); 
        drop_tetromino(delta_time);
        usleep(10000);    
    }
    return 0;
}