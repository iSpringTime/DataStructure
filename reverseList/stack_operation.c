/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : stack_operation.c
  Author        : iSpringTime
  Create        : 2019.10.24
  Description   : stack operation (demo)
******************************************************************************/

#include <stack.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

status push(SeqStack *stack, SElemType input)
{
    if (stack->top >= MAX_SIZE - 1) {
        return ERR;
    }
    stack->top++;
    stack->data[stack->top] = input;
    return OK;
}

status pop(SeqStack *stack, SElemType *output)
{
    if (stack->top < 0) {
        return ERR;
    }
    output = stack->data[stack->top];
    stack->top--;
    return OK;
}

status push_list(ListStack *stack, SElemType input)
{
    ListStackPtr *addStack = NULL;
    
    addStack = (ListStackPtr *)malloc(sizeof(ListStackPtr));
    addStack->data = input;
    addStack->next = stack->top;
    stack->top = addStack;
    stack->count++;

    return OK;
}

status pop_list(ListStack *stack, SElemType *input)
{
    ListStackPtr *tmp = NULL;

    if (stack->count < 1) {
        return ERR;
    }

    *input = stack->top->data;
    tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);
    stack->count--;
    tmp = NULL;

    return OK;
}

status ReversePolishNota()
{
    
}

void main()
{
    
}


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
