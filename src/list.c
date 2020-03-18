/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : List.c
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : list (demo)
******************************************************************************/

#include "list.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "malloc.h"
#include "math.h"
#include "time.h"

void PrintList(ListNode *list)
{
    ListNode *tmp = NULL;
    if (list == NULL) {
        return;
    }

    tmp = list;

    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void ReverseList(ListNode **list)
{
    ListNode *listToRever = *list;
    ListNode *pre = listToRever;
    ListNode *cur = listToRever->next;
    ListNode *next = NULL;

    if ((list == NULL) || (listToRever->next == NULL)) {
        return;
    }

    while (cur != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    listToRever->next = NULL;
    *list = pre;
}

void InsertList(ListNode *list, int num, ElemType elem)
{
    ListNode *chList = list;
    ListNode *addElem = NULL;
    int j = 1;

    while((chList != NULL) && (j < num)) {
        chList = chList->next;
        j++;
    }
    if (chList == NULL || j > num) {
        return;
    }
    addElem = (ListNode *)malloc(sizeof(ListNode));
    addElem->data = elem;
    addElem->next = chList->next;
    chList->next = addElem;
}

void DeleList(ListNode *list, int num)
{
    ListNode *chList = list;
    int j = 1;

    while((chList != NULL) && (j < num)) {
        chList = chList->next;
        j++;
    }
    if (chList == NULL || j > num) {
        return;
    }
    chList->next = chList->next->next;
}

void GetList(ListNode *list, int num, ElemType elem)
{
    ListNode *chList = list;
    int j = 1;

    while((chList != NULL) && (j < num)) {
        chList = chList->next;
        j++;
    }
    if (chList == NULL || j > num) {
        return;
    }
    elem = chList->next->data;
    chList->next = chList->next->next;
}

void CreateList(ListNode **list, int num)
{
    ListNode *tmp, *cur;
    *list = (ListNode *)malloc(sizeof(ListNode));
    cur = *list;

    srand((unsigned int)(time(NULL)));
    for (int i = 0;i < num;i++) {
        tmp = (ListNode*)malloc(sizeof(ListNode));
        tmp->data = rand()%100;
        cur->next = tmp;
        cur = tmp;
    }
    cur->next = NULL;
}

void FreeMemo(ListNode *node)
{
    ListNode *freeAre = node;
    ListNode *tmp = NULL;

    while(freeAre != NULL) {
        tmp = freeAre->next;
        free(freeAre);
        freeAre = tmp;
    }
    node = NULL;
}
