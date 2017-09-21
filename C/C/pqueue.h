//
//  pqueue.h
//  C
//
//  Created by Mac on 2017/9/14.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#ifndef pqueue_h
#define pqueue_h

#include <stdio.h>
#include "heap.h"

typedef Heap PQueue;

#define pqueue_init heap_init
#define pqueue_insert heap_insert
//从优先队列中提取优先队列顶部的元素
#define pqueue_extract heap_extract
//获取优先队列中优先级最高元素
#define pqueue_peek(pqueue) ((pqueue)->tree == NULL ? NULL : (pqueue)->tree[0])
#define pqueue_size heap_size


#endif /* pqueue_h */










