/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : queue_operation.c
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : queue_operation (demo)
******************************************************************************/

#include "queue.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

status EnQueue(QueueList *queueList, QElemType e)
{
  QueuePtr node = NULL;
  node = (QueuePtr)malloc(sizeof(QueueNode));

  node->date = e;
  node->next = NULL;
  queueList->rear->next = node;
  queueList->rear = node;
  return OK;
}

status DeQueue(QueueList *queueList, QElemType *e)
{
  QueuePtr node = NULL;

  if (queueList->rear == queueList->front) {
    return ERR;
  }

  node = queueList->front->next;

  *e = node->date;
  queueList->front->next = node->next;

  if(node == queueList->rear)
    queueList->front = queueList->rear;
  free(node);
  return OK;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
