/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : sort.h
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : queue operation (demo)
******************************************************************************/

#ifndef _SORT_H_
#define _SORT_H_

void swap(int *left, int *right);
void BubbleSort2(int arr[], int num);
void qsort(int a[], int left, int right);
int delSameElem(int arr[], int num, int new_arr[]);
bool delSameElemInsort(int arr[], int length, int *newLength);

#endif