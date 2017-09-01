//
//  clist.h
//  C
//
//  Created by Mac on 2017/8/11.
//  Copyright © 2017年 oldSix. All rights reserved.
//
//循环链表抽象数据类型

#ifndef clist_h
#define clist_h

#include <stdio.h>

typedef struct CListElmt_{
    void *data;
    struct CListElmt_ *next;
}CListElmt;

typedef struct CList_{
    int size;
    int (*math)(const void *key1,const void *key2);
    void (*destroy)(void *data);
    CListElmt *head;
}CList;

//初始化一个链表 O(1)
void clist_init(CList *list,void (*destroy)(void *data));

//销毁链表 O(n)
void clist_destroy(CList *list);

//在链表list的element后面插入一个新元素 O(1)
//插入空链表时，element应为NULL
int clist_ins_next(CList *list,CListElmt *element,const void *data);

//移除链表list的element后面的元素 O(1)
int clist_rem_next(CList *list,CListElmt *element,void **data);

//以下宏皆为O(1)
//返回list中元素的个数
int clist_size(const CList *list);
//返回list中头元素的指针
CListElmt *clist_head(const CList *list);
//element中保存的数据
void *clist_data(const CListElmt *element);
//element的下一个结点
CListElmt *clist_next(const CListElmt *element);

#define clist_size(list) ((list)->size)
#define clist_head(list) ((list)->head)
#define clist_data(element) ((element)->data)
#define clist_next(element) ((element)->next)


#endif /* clist_h */
