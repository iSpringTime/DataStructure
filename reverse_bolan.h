/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : stack.h
  Author        : iSpringTime
  Create        : 2019.10.24
  Description   : stack operation (demo)
******************************************************************************/

/* sqstack.h*/
#ifndef SQSTACK_H_
#define SQSTACK_H_

#define MAXSIZE 32
//栈结构体
typedef struct
{
    int data[MAXSIZE];

    int top;
}sqstack;

sqstack *sqstack_create();  //创建栈
int sqstack_push(sqstack *, int ); //入栈
int sqstack_pop(sqstack *, int *); //出栈
int sqstack_top(sqstack *, int *); //查看栈顶值
int sqstack_is_empty(sqstack *); //判断栈是否为控
void sqstack_display(sqstack *); //显示栈内容，调试用的

#endif
