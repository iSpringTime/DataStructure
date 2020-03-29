/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : queue.h
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : queue operation (demo)
******************************************************************************/

#ifndef _COMMON_DATASTRUCT_H_
#define _COMMON_DATASTRUCT_H_

#define ARRY_SIZE 100

int str2Num(char *str);
void strReverse(char *s);
void strSort(char *str);
int delSameElem(int arr[], int num, int new_arr[]);
bool delSameElemInsort(int arr[], int length, int *newLength);


#endif