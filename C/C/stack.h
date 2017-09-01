//
//  stack.h
//  C
//
//  Created by Mac on 2017/8/11.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include "list.h"

typedef List Stack;

#define stack_init list_init
#define stack_destroy list_destroy


//向stack中压入一个元素 O(1)
int stack_push(Stack *stack,const void *data);
//从stack中弹出一个元素 O(1)
int stack_pop(Stack *stack,void **data);
//皆为 O(1)
//获取栈顶部的元素
void *stack_peek(const Stack *stack);
//获取栈中元素个数
int stack_size(const Stack *stack);

//获取顶元素的信息
#define stack_peek(stack) ((stack)->head == NULL?NULL:(stack)->head->data)
#define stack_size list_size

#endif /* stack_h */


























