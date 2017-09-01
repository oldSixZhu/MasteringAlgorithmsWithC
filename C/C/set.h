//
//  set.h
//  C
//
//  Created by Mac on 2017/8/21.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#ifndef set_h
#define set_h

#include <stdio.h>
#include "list.h"

typedef List Set;

//初始化
void set_init(Set *set,int(*match)(const void *key1,const void *key2),void (*destroy)(void *data));
//销毁
#define set_destroy list_destroy
//插入
int set_insert(Set *set,const void *data);
//移除
int set_remove(Set *set,void **data);
//建立一个集合，set1和set2的并集   O(mn)
int set_union(Set *setu,const Set *set1,const Set *set2);
//建立一个集合，set1和set2的交集   O(mn)
int set_intersection(Set *seti,const Set *set1,const Set *set2);
//建立一个集合，set1和set2的差集   O(mn)
int set_difference(Set *setd,const Set *set1,const Set *set2);
//判断某个成员是否在集合中出现过     O(n)
int set_is_member(const Set *set,const void *data);
//判断set1是否是set2的子集    O(mn)
int set_is_subset(const Set *set1,const Set *set2);
//判断set1是否和set2相等     O(mn)
int set_is_equal(const Set *set1,const Set *set2);
#define set_size(set) ((set)->size)


#endif /* set_h */





























