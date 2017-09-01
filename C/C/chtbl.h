//
//  chtbl.h
//  C
//
//  Created by Mac on 2017/8/23.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#ifndef chtbl_h
#define chtbl_h

#include <stdio.h>
#include "list.h"

typedef struct CHTbl_{
    int buckets;//桶数
    int (*h)(const void *key);
    int (*match)(const void *key1,const void *key2);
    void (*destroy)(void *data);
    int size;
    List *table;
}CHTbl;

//buckets为桶数，
//h指向哈希函数，会将键散列
//match判断两个键是否匹配
//destroy销毁
int chtbl_init(CHTbl *htbl,int buckets,int(*h)(const void *key),int(*match)(const void *key1,const void *key2),void(*destroy)(void *data));

//销毁，删除每个桶中的元素
void chtbl_destroy(CHTbl *htbl);
int chtbl_insert(CHTbl *htbl,const void *data);
int chtbl_remove(CHTbl *htbl,void **data);
//查找
int chtbl_lookup(const CHTbl *htbl,void **data);

#define chtbl_size(htbl) ((htbl)->size)

#endif /* chtbl_h */

























