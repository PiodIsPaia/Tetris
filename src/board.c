#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "board.h"
#include "tetromino.h"

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 15

int board[BOARD_HEIGHT][BOARD_WIDTH] = {0};
Tetromino current_tetromino;
int current_x = 0, current_y = 0;

void init_game()
{
    srand(time(NULL));
    current_tetromino = tetrominos[rand() % TETROMINO_COUNT];
    current_x = BOARD_WIDTH / 2 - current_tetromino.width / 2;
    current_y = 0;
    drop_interval = 0.5f;
    drop_timer = 0.0f;
}

void draw_board()
{
    system("cls");
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            if (board[y][x])
            {
                printf("#");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }

    for (int y = 0; y < current_tetromino.height; y++)
    {
        for (int x = 0; x < current_tetromino.width; x++)
        {
            if (current_tetromino.shape[y][x])
            {
                printf("\033[%d;%dH#", current_y + y, current_x + x + 1);
            }
        }
    }
    fflush(stdout);
}

int check_collision(int x, int y, Tetromino *tetromino)
{
    for (int cy = 0; cy < tetromino->height; cy++)
    {
        for (int cx = 0; cx < tetromino->width; cx++)
        {
            if (tetromino->shape[cy][cx])
            {
                int board_x = x + cx;
                int board_y = y + cy;
                if (board_x < 0 || board_x >= BOARD_WIDTH || board_y < 0 || board_y >= BOARD_HEIGHT)
                {
                    return 1;
                }
                if (board[board_y][board_x])
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void place_tetromino(int x, int y, Tetromino *tetromino)
{
    for (int cy = 0; cy < tetromino->height; cy++)
    {
        for (int cx = 0; cx < tetromino->width; cx++)
        {
            if (tetromino->shape[cy][cx])
            {
                board[y + cy][x + cx] = 1;
            }
        }
    }
}

void drop_tetromino(float delta_time)
{
    drop_timer += delta_time;

    if (drop_timer >= drop_interval)
    {
        if (!check_collision(current_x, current_y + 1, &current_tetromino))
        {
            current_y++;
        }
        else
        {
            place_tetromino(current_x, current_y, &current_tetromino);
            current_tetromino = tetrominos[rand() % TETROMINO_COUNT];
            current_x = BOARD_WIDTH / 2 - current_tetromino.width / 2;
            current_y = 0;
            if (check_collision(current_x, current_y, &current_tetromino))
            {
                printf("GAME OVER\n");
                exit(0);
            }
        }
        drop_timer = 0.0f;
    }  
}

void handle_input(float delta_time)
{
    if (_kbhit())
    {
        char ch = _getch();
        switch (ch)
        {
        case 'a':
            if (!check_collision(current_x - 1, current_y, &current_tetromino))
            {
                current_x--;
            }
            break;
        case 'd':
            if (!check_collision(current_x + 1, current_y, &current_tetromino))
            {
                current_x++;
            }
            break;
        case 's':
            drop_tetromino(delta_time);
            break;
        case 'w':
            break;
        }
    }
}
