//
//  queue.h
//  C
//
//  Created by Mac on 2017/8/11.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include "list.h"

typedef List Queue;

#define queue_init list_init
#define queue_destroy list_destroy
//往队列尾部插入元素 O(1)
int queue_enqueue(Queue *queue,const void *data);
//从队列头部删除元素 O(1)
int queue_dequeue(Queue *queue,void **data);

#define queue_peek(queue) ((queue)->head == NULL?NULL:(queue)->head->data)
#define queue_size list_size


#endif /* queue_h */


























