//
//  chtbl.c
//  C
//
//  Created by Mac on 2017/8/23.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#include "chtbl.h"
#include <string.h>
#include <stdlib.h>

int chtbl_init(CHTbl *htbl,int buckets,int(*h)(const void *key),int(*match)(const void *key1,const void *key2),void(*destroy)(void *data))
{
    if ((htbl->table = (List *)malloc(buckets *sizeof(List))) == NULL)
    {
        return -1;
    }
    htbl->buckets = buckets;
    for (int i=0; i<htbl->buckets; i++)
    {
        list_init(&htbl->table[i], destroy);
    }
    
    htbl->h = h;
    htbl->match = match;
    htbl->destroy = destroy;
    
    htbl->size = 0;
    return 0;
}

//销毁，删除每个桶中的元素
void chtbl_destroy(CHTbl *htbl)
{
    for (int i=0; i<htbl->buckets; i++)
    {
        list_destroy(&htbl->table[i]);
    }
    free(htbl->table);
    memset(htbl, 0, sizeof(CHTbl));
    return;
}

int chtbl_insert(CHTbl *htbl,const void *data)
{
    void *temp;
    int bucket,retval;
    temp = (void *)data;
    //判断是否已经存在
    if (chtbl_lookup(htbl, &temp) == 0)
    {
        return 1;
    }
    //哈希key
    bucket = htbl->h(data) % htbl->buckets;
    //插入
    if((retval=list_ins_next(&htbl->table[bucket], NULL, data))==0)
    {
        htbl->size++;
    }
    return retval;
}

int chtbl_remove(CHTbl *htbl,void **data)
{
    ListElmt *element,*prev;
    int bucket;
    //哈希key
    bucket = htbl->h(data) % htbl->buckets;
    prev = NULL;
    for (element = list_head(&htbl->table[bucket]); element != NULL; element = list_next(element))
    {
        if (htbl->match(*data,list_data(element)))
        {
            if (list_rem_next(&htbl->table[bucket], prev, data)==0)
            {
                htbl->size--;
                return 0;
            }else{
                return -1;
            }
        }
        prev = element;
    }
    return -1;
}

//查找
int chtbl_lookup(const CHTbl *htbl,void **data)
{
    ListElmt *element;
    int bucket;
    //哈希key
    bucket = htbl->h(data) % htbl->buckets;
    for (element = list_head(&htbl->table[bucket]); element != NULL; element = list_next(element))
    {
        if (htbl->match(*data,list_data(element)))
        {
            *data = list_data(element);
            return 0;
        }
    }
    return -1;
}



















