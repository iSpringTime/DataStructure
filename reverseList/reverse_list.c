/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : reverseList.c
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : reverse list (demo)
******************************************************************************/

#include <reverseList.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

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
        freeAre = tmp->next;
    }
    node = NULL;
}

void main()
{
    ListNode *head = NULL;
    
    CreateList(&head, 5);
    printf("\n**************** before reverse ****************\n");
    PrintList(head->next);

    ReverseList(&head->next);
    printf("\n**************** after reverse ****************\n");
    PrintList(head->next);

    FreeMemo(head);
}


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
