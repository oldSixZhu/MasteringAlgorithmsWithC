//
//  qksort.c
//  C
//
//  Created by Mac on 2017/9/20.
//  Copyright © 2017年 oldSix. All rights reserved.
//快速排序

#include "qksort.h"
#include <stdlib.h>
#include <string.h>
#include "issort.h"

//分割数据
int partition(void *data,int esize,int i,int k,int(*compare)(const void *key1,const void *key2))
{
    char *a = data;
    void *pval,*temp;
    int r[3];
    //初始化
    if ((pval = malloc(esize)) == NULL) {
        return -1;
    }
    if ((temp = malloc(esize)) == NULL) {
        free(pval);
        return -1;
    }
    //中位数法找出分割值
    r[0] = (rand()%(k-i+1)) +i;
    r[1] = (rand()%(k-i+1)) +i;
    r[2] = (rand()%(k-i+1)) +i;
    issort(r, 3, sizeof(int), compare);
    memcpy(pval, &a[r[1]*esize], esize);
    //根据分割值分成两个区
    i--;
    k++;
    while (1) {
        //移动左边直到找到一个元素在错误的分区
        do {
            k--;
        } while (compare(&a[k * esize],pval) > 0);
        //移动右边直到找到一个元素在错误的分区
        do {
            i++;
        } while (compare(&a[i * esize],pval) < 0);
       
        if (i >= k) {
            //一旦i和k重合，那么左边的元素将小于等于它，右边的元素将大于等于它，停止分区
            break;
        }else{
            //交换元素
            memcpy(temp, &a[i * esize], esize);
            memcpy(&a[i * esize], &a[k * esize], esize);
            memcpy(&a[k * esize], temp, esize);
        }
    }
    free(pval);
    free(temp);
    //返回划分两个区的位置
    return k;
}

int qksort(void *data,int size,int esize,int i,int k,int(*compare)(const void *key1,const void *key2))
{
    int j;
    //可以进一步划分时停止递归
    while (i<k){
        //确定分区的元素
        if ((j = partition(data, esize, i, k, compare)) < 0) {
            return -1;
        }
        //递归左边的分区
        if (qksort(data, size, esize, i, j, compare) < 0) {
            return -1;
        }
        //迭代和排序右边的分区
        i = j+1;
    }
    return 0;
}
























