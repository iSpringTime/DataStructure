/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : reverseList.c
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : reverse list (demo)
******************************************************************************/

#include "list.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

int main()
{
    ListNode *head = NULL;
    ElemType input = 100;
    
    CreateList(&head, 5);
    printf("\n**************** origin list ****************\n");
    PrintList(head->next);

    ReverseList(&head->next);
    printf("\n**************** reversered ****************\n");
    PrintList(head->next);

    InsertList(head, 3, input);
    printf("\n**************** inserted ****************\n");
    PrintList(head->next);

    DeleList(head, 3);
    printf("\n**************** deleted ****************\n");
    PrintList(head->next);

    FreeMemo(head);
    return 1;
}


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
