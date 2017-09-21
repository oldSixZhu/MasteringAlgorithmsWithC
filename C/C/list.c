//
//  list.c
//  C
//
//  Created by Mac on 2017/8/10.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#include "list.h"


//初始化一个链表
void list_init(List *list,void (*destroy)(void *data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    return;
}

//销毁链表
void list_destroy(List *list)
{
    void *data;
    //每个元素都调用一次
    while (list_size(list)>0)
    {
        if (list_rem_next(list, NULL, (void **)&data)==0 && list->destroy != NULL)
        {
            list_destroy(data);
        }
    }
    //将list中当前位置后面的n个字节用0替换并返回list
    memset(list,0,sizeof(List));
    return;
}

//在链表list的element后面插入一个新元素
int list_ins_next(List *list,ListElmt *element,const void *data)
{
    ListElmt *new_element;
    if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
    {
        return -1;
    }
    new_element->data = (void *)data;
    //当新的元素将插入链表头部
    if (element == NULL)
    {
        if (list_size(list) == 0)
        {
            list->tail = new_element;
        }
        //一般是将新元素的next指针指向它之后的那个元素，
        //然后将新元素位置之前的结点next指针指向新插入的元素
        new_element->next = list->head;
        list->head = new_element;
    }
    else
    {
        if (element->next == NULL)
        {
            list->tail = new_element;
        }
        new_element->next = element->next;
        element->next = new_element;
    }
    list->size++;
    return 0;
}

//移除链表list的element后面的元素
int list_rem_next(List *list,ListElmt *element,void **data)
{
    ListElmt *old_element;
    if (list_size(list) == 0)
    {
        return -1;
    }
    //移除头结点
    if (element == NULL)
    {
        //将要移除的目标节点前一个元素的next指针指向目标节点下一个元素
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;
        //当移除操作使整个链表称为空链表
        if (list_size(list) == 1)
        {
            list->tail = NULL;
        }
    }
    else
    {
        if (element->next == NULL)
        {
            return -1;
        }
        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;
        if (element->next == NULL)
        {
            list->tail = element;
        }
    }
    
    free(old_element);
    list->size--;
    return 0;
}









