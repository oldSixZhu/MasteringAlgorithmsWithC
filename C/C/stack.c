//
//  stack.c
//  C
//
//  Created by Mac on 2017/8/11.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#include "stack.h"

//向stack中压入一个元素 O(1)
int stack_push(Stack *stack,const void *data)
{
    return list_ins_next(stack, NULL, data);
}
//从stack中弹出一个元素 O(1)
int stack_pop(Stack *stack,void **data)
{
    return list_rem_next(stack, NULL, data);
}






