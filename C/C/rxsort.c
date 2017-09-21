//
//  rxsort.c
//  C
//
//  Created by Mac on 2017/9/20.
//  Copyright © 2017年 oldSix. All rights reserved.
//基数排序

#include "rxsort.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int rxsort(int *data,int size,int p,int k)
{
    int *counts,*temp;
    int index,pval,i,j,n;
    if ((counts = (int *)malloc(k * sizeof(int))) == NULL) {
        return -1;
    }
    if ((temp = (int *)malloc(size * sizeof(int))) == NULL) {
        return -1;
    }
    
    for (n=0; n<p; n++) {
        for (i=0; i<k; i++) {
            counts[i] = 0;
        }
        pval = (int)pow((double)k, (double)n);
        for (j = 0; j < size; j++) {
            index = (int)(data[j] / pval) % k;
            counts[index]=counts[index] + 1;
        }
        for (i = 1; i < k; i++) {
            counts[i] = counts[i] + counts[i-1];
        }
        for (j = size-1; j >= 0; j--) {
            index = (int)(data[j] / pval) % k;
            temp[counts[index]-1] = data[j];
            counts[index] = counts[index] - 1;
        }
        memcpy(data, temp, size * sizeof(int));
    }
    free(counts);
    free(temp);
    return 0;
}



























