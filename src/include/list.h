/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : List.h
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : list (demo)
******************************************************************************/

#ifndef _LIST_H_
#define _LIST_H_

typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
} ListNode;

void PrintList(ListNode *list);
void ReverseList(ListNode **list);
void InsertList(ListNode *list, int num, ElemType elem);
void GetList(ListNode *list, int num, ElemType elem);
void DeleList(ListNode *list, int num);
void CreateList(ListNode **list, int num);
void FreeMemo(ListNode *node);

#endif