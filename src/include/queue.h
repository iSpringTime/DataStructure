/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : queue.h
  Author        : iSpringTime
  Create        : 2019.10.24
  Description   : queue operation (demo)
******************************************************************************/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

typedef int QElemType;
typedef struct QNode {
  QElemType date;
  struct QNode *next;
}QueueNode, *QueuePtr;

typedef struct {
  QueuePtr rear, front;
}QueueList;

status EnQueue(QueueList *queueList, QElemType e);
status DeQueue(QueueList *queueList, QElemType *e);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
