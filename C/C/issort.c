//
//  issort.c
//  C
//
//  Created by Mac on 2017/9/19.
//  Copyright © 2017年 oldSix. All rights reserved.
//插入排序

#include "issort.h"
#include <stdlib.h>
#include <string.h>


/*
 *插入排序
 *参数：data:待排序的数组
 *      size:数组元素的个数
 *      esize:每个元素的大小
 *      compare:函数指针，比较函数大小的函数
 *返回值：成功返回0，否则-1，data包含已排序的元素
 */

int issort(void *data,int size,int esize,int (*compare)(const void *key1,const void *key2) )
{
    char *a = data;
    void *key;
    int i;
    if ((key = (char *)malloc(esize)) == NULL)
    {
        return -1;
    }
    for (int j=1; j<size; j++)
    {
        memcpy(key, &a[j * esize], esize);
        i = j-1;
        while (i>=0 && compare(&a[i * esize],key) > 0)
        {
            memcpy(&a[(i+1) * esize], &a[i * esize], esize);
            i--;
        }
        memcpy(&a[(i+1) * esize], key, esize);
    }
    free(key);
    return 0;
}

































