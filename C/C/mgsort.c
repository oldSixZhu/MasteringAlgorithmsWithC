//
//  mgsort.c
//  C
//
//  Created by Mac on 2017/9/20.
//  Copyright © 2017年 oldSix. All rights reserved.
//归并排序

#include "mgsort.h"
#include <stdlib.h>
#include <string.h>

//将两个有序集合合并成一个有序集合
int merge(void *data,int esize,int i,int j,int k,int(*compare)(const void *key1,const void *key2))
{
    char *a = data,*m;
    int ipos,jpos,mpos;
    //初始化
    ipos = i;
    jpos = j+1;
    mpos = 0;
    if ((m = (char *)malloc(esize *((k-i)+1))) == NULL){
        return -1;
    }
    //当两个部分都有元素合并时继续
    while (ipos <= j || jpos <= k){
        if (ipos > j){
            //左部分没有元素要合并了
            while (jpos <= k) {
                memcpy(&m[mpos * esize], &a[jpos * esize], esize);
                jpos++;
                mpos++;
            }
            continue;
        }
        else if (jpos > k){
            //右部分没有元素要合并了
            while (ipos <= j) {
                memcpy(&m[mpos * esize], &a[ipos * esize], esize);
                ipos++;
                mpos++;
            }
            continue;
        }
        //追加下一个元素到合并元素
        if (compare(&a[ipos * esize],&a[jpos * esize]) < 0) {
            memcpy(&m[mpos * esize], &a[ipos * esize], esize);
            ipos++;
            mpos++;
        }
        else{
            memcpy(&m[mpos * esize], &a[jpos * esize], esize);
            jpos++;
            mpos++;
        }
    }
    memcpy(&a[i * esize], m, esize * ((k-i)+1));
    free(m);
    return 0;
}


int mgsort(void *data,int size,int esize,int i,int k,int(*compare)(const void *key1,const void *key2))
{
    int j;
    if (i < k) {
        //确定分割点
        j = (int)((i+k-1)/2);
        //递归排序
        if (mgsort(data, size, esize, i, j, compare) < 0) {
            return -1;
        }
        if (mgsort(data, size, esize, j+1, k, compare) < 0) {
            return -1;
        }
        //合并
        if (merge(data, esize, i, j, k, compare) < 0) {
            return -1;
        }
    }
    return 0;
}


























