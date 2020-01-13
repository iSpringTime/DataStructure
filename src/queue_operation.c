#include "queue.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "malloc.h"
#include "math.h"

//初始化
//开始必然是空队列，队尾指针和队头指针都指向头结点
void initQueue(LinkQueue *queue)
{
    //初始化头结点
    queue->front = queue->rear = (Queue)malloc(sizeof(QNode));
    
    if (NULL == queue->front) {
        exit(0);
    }
    
    queue->front->next = NULL;
}

//判空
bool isEmpty(LinkQueue queue)
{
    return queue.rear == queue.front ? true : false;
}

//入队,只在一端入队，另一端出队，同样入队不需要判满
void insertQueue(LinkQueue *queue, QElemType temp)
{
    Queue q = (Queue)malloc(sizeof(QNode));
    
    if (NULL == q) {
        exit(0);
    }

    //插入数据
    q->data = temp;
    q->next = NULL;

    //rear 总是指向队尾元素
    queue->rear->next = q;
    queue->rear = q;
}

//出队，需要判空
void deleteQueue(LinkQueue *queue, QElemType *ret)
{
    Queue q = NULL;

    if (!isEmpty(*queue)) {
        q = queue->front->next;
        *ret = q->data;
        queue->front->next = q->next;
        
        //这句很关键，不能丢
        if (queue->rear == q) {
            queue->rear = queue->front;
        }
        
        free(q);
    }
}
