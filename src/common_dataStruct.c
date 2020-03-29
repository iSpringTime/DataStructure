/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : common_dataStruct.c
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : common_dataStruct (demo)
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <time.h>

#include <common_dataStruct.h>

/* 字符串转数字 */
int str2Num(char *str) 
{
    int cont = 0;
    int num = 0;
    int tmp = 0;

    printf("the input str:%s \n", str);
    if(str == NULL)
        exit(0);

    while (*(str+cont) != '\0') {
        tmp = *(str+cont) - '0';
        //printf("%d \n", tmp);
        num = num * 10 + tmp;
        cont++;
    }

    return num;
}

void strReverse(char *s)
{
    int length = strlen(s);
    char c;
    for (int i = 0,j = length - 1;i < j;i++,j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int delSameElem(int arr[], int num, int new_arr[]) 
{
    int i;
    int newArryLen = 0;

    bool flag[ARRY_SIZE] = {0};
    for (i = 0;i < num;i++) {
        if(flag[arr[i]] == false) {
            new_arr[newArryLen++] = arr[i];
            flag[arr[i]] = true;
        }
    }
    return newArryLen;
}

bool delSameElemInsort(int arr[], int length, int *newLength)
{
    if(arr == NULL || length == 0) {
        return false;
    }

    int count = 1;
    for (int i = 1;i < length;i++) {
        if (arr[i] == arr[i - 1]) {
            continue;
        } else {
             arr[count++] = arr[i];
        }
    }
    *newLength = count;
    return true;
}

void strSort(char *str)
{
    int length = strlen(str);
    int i;
    int j;
    char temp;

    for(i=0; i< length -1; ++i) {
        for(j=i+1; j<length ; ++j)
        {
            if(str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}