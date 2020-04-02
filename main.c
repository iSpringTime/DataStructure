#include <stdio.h>
#include "securec.h"

char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes);

int main() {
    char* board[4] = {};
    char a1[] = {'E', 'E', 'E', 'E', 'E'};
    char a2[] = {'E', 'E', 'M', 'E', 'E'};
    char a3[] = {'E', 'E', 'E', 'E', 'E'};
    char a4[] = {'E', 'E', 'E', 'E', 'E'};

    char* board2[5] = {};
    char a11[] = {'M'};
    char a12[] = {'M'};
    char a13[] = {'E'};
    char a14[] = {'M'};
    char a15[] = {'E'};

    char **map = NULL;
    int returnSize;
    int *returnColumn = NULL;
    int boardColun[] = {1,1,1,1,1};
    int click[] = {2,0};
    int i,j;

    board2[0] = a11;
    board2[1] = a12;
    board2[2] = a13;
    board2[3] = a14;
    board2[4] = a15;

    map = updateBoard(board2, 5, boardColun, click, 2, &returnSize, &returnColumn);

    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < returnColumn[0]; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}


