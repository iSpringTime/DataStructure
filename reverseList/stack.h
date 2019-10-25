/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : stack.h
  Author        : iSpringTime
  Create        : 2019.10.24
  Description   : stack operation (demo)
******************************************************************************/

#ifndef _STACK_LIST_H_
#define _STACK_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

typedef int status;
#define ERR 1
#define OK  0
#define MAX_SIZE 20
typedef int SElemType;
typedef struct {
    SElemType data[MAX_SIZE];
    int top;
} SeqStack;

typedef struct  StackNode {
  SElemType data;
  StackNode *next;
} ListStackPtr;

typedef struct ListStack {
  ListStackPtr *top;
  int count;
} ListStack;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
