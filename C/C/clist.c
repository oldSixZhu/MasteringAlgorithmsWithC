//
//  clist.c
//  C
//
//  Created by Mac on 2017/8/11.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#include "clist.h"
#include <string.h>
#include <stdlib.h>

//初始化list指定的双向链表
void clist_init(CList *list,void(*destroy)(void *data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    return;
}

//销毁链表
void clist_destroy(CList *list)
{
    void *data;
    while (clist_size(list) >0)
    {
        if (clist_rem_next(list, list->head, (void **)&data)==0
            && list->destroy != NULL)
        {
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(CList));
    return;
}

//将元素插入list指定的双向链表中element元素之后
int clist_ins_next(CList *list,CListElmt *element,const void *data)
{
    CListElmt *new_element;
    new_element = (CListElmt *)malloc(sizeof(CListElmt));
    if (new_element == NULL)
    {
        return -1;
    }
    new_element->data = (void *)data;
    if (clist_size(list) == 0)
    {
        new_element->next = new_element;
        list->head = new_element;
    }
    else
    {
        new_element->next = element->next;
        element->next = new_element;
    }
    list->size++;
    return 0;
}

//移除链表list的element后面的元素
int clist_rem_next(CList *list,CListElmt *element,void **data)
{
    CListElmt *old_element;
    if (clist_size(list) == 0)
    {
        return -1;
    }
    *data = element->next->data;
    if (element->next == element)
    {
        old_element = element->next;
        list->head = NULL;
    }
    else
    {
        old_element = element->next;
        element->next = element->next->next;
        if (old_element == clist_head(list))
        {
            list->head = old_element->next;
        }
    }
    free(old_element);
    list->size--;
    return 0;
}
