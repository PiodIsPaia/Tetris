#include "tetromino.h"

Tetromino tetrominos[] = {
    {2, 2, {{1, 1}, {1, 1}}},
    {4, 2, {{0, 1, 0, 0}, {1, 1, 1, 0}}},
    {4, 2, {{1, 1, 0, 0}, {0, 1, 1, 0}}},
    {4, 2, {{0, 1, 1, 0}, {1, 1, 0, 0}}},
    {1, 4, {{1}, {1}, {1}, {1}}},
    {3, 3, {{1, 1, 1}, {1, 0, 0}}},
    {3, 3, {{1, 1, 1}, {0, 0, 1}}}};

const int TETROMINO_COUNT = sizeof(tetrominos) / sizeof(Tetromino);
