/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : reverseList.h
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : reverse list (demo)
******************************************************************************/

#ifndef _REVERSE_LIST_H_
#define _REVERSE_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} ListNode;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
