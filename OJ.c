#include "OJ.h"
#include "common_dataStruct.h"
#include "list.h"
#include "queue.h"
#include "sort.h"

// #include<iostream>
// #include<algorithm>

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "malloc.h"
#include "math.h"
#include "time.h"

int* divingBoard(int shorter, int longer, int k, int* returnSize){
    int num;
    int numSize = 0;
    int newLength = 0;
    int *inPut;

    num = k;
    inPut = (int *) malloc((num+1)*sizeof(int));
    
    if(k==0)
    {
        *returnSize=0;
        free(inPut);
        inPut=NULL;
        return inPut;
    }

    for (int i = num;i >= 0;i--) {
        inPut[numSize++] = i * shorter + (num-i) * longer;
    }

    BubbleSort2(inPut, num+1);
    delSameElemInsort(inPut, num+1, &newLength);

    * returnSize = newLength;
    return inPut;
}

int main()
{
    int num;
    int newLength = 0;
    int shorter = 1;
    int longer = 2;

    scanf("%d %d %d", &shorter, &longer, &num);

    (void)divingBoard(shorter, longer, num, &newLength);
}
