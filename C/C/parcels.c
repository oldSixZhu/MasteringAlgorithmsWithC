//
//  parcels.c
//  C
//
//  Created by Mac on 2017/9/14.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#include "parcels.h"
#include "pqueue.h"
#include "parcel.h"
#include <string.h>
#include <stdlib.h>

//取到最高优先级的包裹
int get_parcel(PQueue *parcels,Parcel *parcel)
{
    Parcel *data;
    if (pqueue_size(parcels) == 0)
    {
        return -1;
    }
    else
    {
        if (pqueue_extract(parcels,(void **)&data) != 0)
        {
            return -1;
        }
        else
        {
            memcpy(parcel,data,sizeof(Parcel));
            free(data);
        }
    }
    return 0;
}

//将一个包裹插入一个优先队列中，并按照优先级找到它在队列中的位置
int put_parcel(PQueue *parcels,const Parcel *parcel)
{
    Parcel *data;
    if ((data = (Parcel *)malloc(sizeof(Parcel))) == NULL)
    {
        return -1;
    }
    memcpy(data, parcel, sizeof(Parcel));
    
    if (pqueue_insert(parcels,data) != 0)
    {
        return -1;
    }
    return 0;
}



















