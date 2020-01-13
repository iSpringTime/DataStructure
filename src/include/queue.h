/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : queue.h
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : queue operation (demo)
******************************************************************************/

#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int QElemType;
typedef struct QNode{
    QElemType data;
    struct QNode *next;
} QNode, *Queue;

//队列的结构，嵌套
typedef struct{
    Queue front;
    Queue rear;
} LinkQueue;

void initQueue(LinkQueue *queue);
bool isEmpty(LinkQueue queue);
void insertQueue(LinkQueue *queue, QElemType temp);
void deleteQueue(LinkQueue *queue, QElemType *ret);

#endif
