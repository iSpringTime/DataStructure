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

