//
//  dlist.h
//  C
//
//  Created by Mac on 2017/8/10.
//  Copyright © 2017年 oldSix. All rights reserved.
//
//双向链表抽象数据类型

#ifndef dlist_h
#define dlist_h

#include <stdio.h>

typedef struct DListElmt_{
    void *data;
    struct DListElmt_ *prev;
    struct DListElmt_ *next;
}DListElmt;

typedef struct DList_{
    int size;
    int (*match)(const void*key1,const void *key2);
    void (*destroy)(void *data);
    DListElmt *head;
    DListElmt *tail;
}DList;

//初始化list指定的双向链表    O(1)
//destroy提供释放动态分配空间的方法
void dlist_init(DList *list,void(*destroy)(void *data));

//销毁链表  O(n)
void dlist_destroy(DList *list);

//将元素插入list指定的双向链表中element元素之后  O(1)
//插入空链表时，element应为NULL
int dlist_ins_next(DList *list,DListElmt *element,const void *data);

//将元素插入list指定的双向链表中element元素之前  O(1)
//插入空链表时，element应为NULL
int dlist_ins_prev(DList *list,DListElmt *element,const void *data);

//移除list指定的双向链表中element指定的元素     O(1)
int dlist_remove(DList *list,DListElmt *element,void **data);

//以下宏皆为O(1)
//返回list中元素的个数
int dlist_size(const DList *list);
//返回list中头元素
DListElmt *dlist_head(const DList *list);
//返回list中尾元素
DListElmt *dlist_tail(const DList *list);
//判断element是否为链表头元素
int dlist_is_head(const DListElmt *element);
//判断element是否为链表尾元素
int dlist_is_tail(const DListElmt *element);
//返回element的数据域
void *dlist_data(const DListElmt *element);
//返回element下一个元素
DListElmt *dlist_next(const DListElmt *element);
//返回element前驱元素
DListElmt *dlist_prev(const DListElmt *element);

#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)

#define dlist_is_head(element) ((element)->prev == NULL?1:0)
#define dlist_is_tail(element) ((element)->next == NULL?1:0)

#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->prev)

#endif /* dlist_h */











