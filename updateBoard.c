/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **g_map = NULL;

char** mallocTwo(int m, int n)
{
    char **pp = NULL;
    int i;

    pp = malloc(m * sizeof(char *));
    if (pp == NULL) {
     return NULL;
    }
    for (i = 0; i < m; i++) {
     pp[i] = malloc(n);
     memset(pp[i], 0, n);
    }
    return pp;
}
void copyTwo(char **pp1, char **pp2, int m, int n)
{
    int i,j;

    for (i = 0; i < m; i++) {
        for (j =0; j < n; j++) {
            pp1[i][j] = pp2[i][j];
        }
    }
}

void upgradeBoardBySearch(int maxM, int maxN, int clickM, int clickN)
{
    int c;
    int i;
    int tM,tN;
    int sumM = 0;

    int direct[][2] = {{-1, 0}, {-1,1},{0,1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    c = g_map[clickM][clickN];

    if (c == 'M') {
        return;
    }

    if (c != 'E') {
        return ;
    }

    for (i = 0; i < 8; i++) {
        tM = clickM + direct[i][0];
        tN = clickN + direct[i][1];
        if (tM < 0 || tM > maxM || tN < 0 || tN > maxN ) {
            continue;
        }
        if (g_map[tM][tN] == 'M') {
            sumM++;
            continue;
        }
    }

    if (sumM > 0) {
        g_map[clickM][clickN] = sumM + '0';
        return;
    }
    g_map[clickM][clickN] = 'B';

    for (i = 0; i < 8; i++) {
        tM = clickM + direct[i][0];
        tN = clickN + direct[i][1];
        if (tM < 0 || tM > maxM || tN < 0 || tN > maxN ) {
            continue;
        }
        upgradeBoardBySearch(maxM, maxN, tM, tN);
    }
    return;
}

char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
    int clickM, clickN;
    int i;
    int *column = NULL;

    if (boardSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    g_map = mallocTwo(boardSize, boardColSize[0]);
    copyTwo(g_map, board, boardSize, boardColSize[0]);

    column = malloc(sizeof(int) * boardSize);
    for (i = 0; i < boardSize; i++) {
        column[i] = boardColSize[0];
    }
    *returnColumnSizes = column;
    *returnSize = boardSize;

    clickM = click[0];
    clickN = click[1];
    if (g_map[clickM][clickN] == 'M') {
        g_map[clickM][clickN] = 'X';
        return g_map;
    }

    upgradeBoardBySearch(boardSize - 1, boardColSize[0] - 1, clickM, clickN);
    return g_map;
}