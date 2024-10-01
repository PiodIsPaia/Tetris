#ifndef TETROMINO_H
#define TETROMINO_H

typedef struct
{
    int width;
    int height;
    int shape[4][4];
} Tetromino;

extern Tetromino tetrominos[];
extern const int TETROMINO_COUNT;

#endif
