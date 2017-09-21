//
//  mgsort.h
//  C
//
//  Created by Mac on 2017/9/20.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#ifndef mgsort_h
#define mgsort_h

#include <stdio.h>

int mgsort(void *data,int size,int esize,int i,int k,int(*compare)(const void *key1,const void *key2));

#endif /* mgsort_h */
