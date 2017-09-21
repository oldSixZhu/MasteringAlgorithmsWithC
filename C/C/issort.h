//
//  issort.h
//  C
//
//  Created by Mac on 2017/9/19.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#ifndef issort_h
#define issort_h

#include <stdio.h>

int issort(void *data,int size,int esize,int (*compare)(const void *key1,const void *key2) );
int compare(const void *key1,const void *key2);

#endif /* issort_h */
