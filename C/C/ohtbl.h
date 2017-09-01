//
//  ohtbl.h
//  C
//
//  Created by Mac on 2017/8/24.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#ifndef ohtbl_h
#define ohtbl_h

#include <stdio.h>

typedef struct OHTbl_{
    int     positions;//哈希表中分配的槽位数目
    void    *vacated;//曾经删除的一个元素
    
    int     (*h1)(const void *key);
    int     (*h2)(const void *key);
    int     (*match)(const void *key1,const void *key2);
    void    (*destroy)(void *data);
    
    int     size;
    void    **table;//存储元素的数组
}OHTbl;


//positions为槽位的个数
//h1，h2指向哈希函数，会将键散列
//match判断两个键是否匹配
//destroy销毁
int ohtbl_init(OHTbl *htbl,int positions,int(*h1)(const void *key),int(*h2)(const void *key),int(*match)(const void *key1,const void *key2),void(*destroy)(void *data));

//销毁
void ohtbl_destroy(OHTbl *htbl);
int ohtbl_insert(OHTbl *htbl,const void *data);
int ohtbl_remove(OHTbl *htbl,void **data);
//查找
int ohtbl_lookup(const OHTbl *htbl,void **data);

#define ohtbl_size(htbl) ((htbl)->size)


#endif /* ohtbl_h */
