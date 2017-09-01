//
//  queue.c
//  C
//
//  Created by Mac on 2017/8/11.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#include "queue.h"


int queue_enqueue(Queue *queue,const void *data)
{
    return list_ins_next(queue, list_tail(queue), data);
}

int queue_dequeue(Queue *queue,void **data)
{
    return list_rem_next(queue, NULL, data);
}






























