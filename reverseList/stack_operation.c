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

void main()
{
    
}


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
