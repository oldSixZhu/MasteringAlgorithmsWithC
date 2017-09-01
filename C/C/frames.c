//
//  frames.c
//  C
//
//  Created by Mac on 2017/8/10.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#include "frames.h"
#include "list.h"
#include <stdlib.h>

//从空闲页帧链表中获取空闲页帧号
int alloc_frame(List *frames)
{
    int frame_number = 0;
    int *data;
    if (list_size(frames)==0)
    {
        return -1;
    }
    else
    {
        if (list_rem_next(frames, NULL, (void **)&data)!=0)
            {
                return -1;
        }
        else
        {
            frame_number = *data;
            free(data);
        }
    }
    return frame_number;
}

//接受一个页帧号并将其放回到空闲页帧链表中
int free_frame(List *frames,int frame_number)
{
    int *data;
    data=(int *)malloc(sizeof(int));
    if (data == NULL)
    {
        return -1;
    }
    *data = frame_number;
    if (list_ins_next(frames, NULL, data) != 0)
    {
        return -1;
    }
    return 0;
}













