//
//  ctsort.c
//  C
//
//  Created by Mac on 2017/9/20.
//  Copyright © 2017年 oldSix. All rights reserved.
//计数排序，桶排序

#include "ctsort.h"
#include <stdlib.h>
#include <string.h>

int ctsort(int *data,int size,int k)
{
    int *counts,*temp;
    int i,j;
    if ((counts = (int *)malloc(k * sizeof(int))) == NULL) {
        return -1;
    }
    if ((temp = (int *)malloc(size * sizeof(int))) == NULL) {
        return -1;
    }
    for (i = 0; i < k; i++) {
        counts[i] = 0;
    }
    for (j = 0; j < size; j++) {
        counts[data[j]] = counts[data[j]] + 1;
    }
    for (i = 1; i < k; i++) {
        counts[i] = counts[i] + counts[i-1];
    }
    for (j = size-1; j>=0; j--) {
        temp[counts[data[j]] - 1] = data[j];
        counts[data[j]] = counts[data[j]] - 1;
    }
    memcpy(data, temp, size * sizeof(int));
    free(counts);
    free(temp);
    return 0;
}
























