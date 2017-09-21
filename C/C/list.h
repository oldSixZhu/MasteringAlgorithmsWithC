//
//  list.h
//  C
//
//  Created by Mac on 2017/8/10.
//  Copyright © 2017年 oldSix. All rights reserved.
//
//链表抽象数据类型

#ifndef list_h
#define list_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListElmt_{
    void *data;
    struct ListElmt_ *next;
}ListElmt;

typedef struct List_{
    int size;
    int (*math)(const void *key1,const void *key2);
    void (*destroy)(void *data);
    ListElmt *head;
    ListElmt *tail;
}List;

//初始化一个链表 O(1)
void list_init(List *list,void (*destroy)(void *data));

//销毁链表 O(n)
void list_destroy(List *list);

//在链表list的element后面插入一个新元素,如果element为NULL，代表插入 头部 O(1)
int list_ins_next(List *list,ListElmt *element,const void *data);

//移除链表list的element后面的元素，如果element为NULL，则移除链表头元素 O(1)
int list_rem_next(List *list,ListElmt *element,void **data);

//以下宏皆为O(1)
//返回list中元素的个数
int list_size(const List *list);
//返回list中头元素的指针
ListElmt *list_head(const List *list);
//返回list中尾元素的指针
ListElmt *list_tail(const List *list);
//判断element是否为头结点
int list_is_head(const ListElmt *element);
//判断element是否为尾结点
int list_is_tail(const ListElmt *element);
//element中保存的数据
void *list_data(const ListElmt *element);
//element的下一个结点
ListElmt *list_next(const ListElmt *element);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list,element) ((element) == (list)->head?1:0)
#define list_is_tail(element) ((element)->next == NULL?1:0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif /* list_h */














