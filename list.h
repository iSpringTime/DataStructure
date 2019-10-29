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

#include "common.h"
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

void PrintList(ListNode *list);
void ReverseList(ListNode **list);
void InsertList(ListNode *list, int num, ElemType elem);
void DeleList(ListNode *list, int num);
void CreateList(ListNode **list, int num);
void FreeMemo(ListNode *node);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
