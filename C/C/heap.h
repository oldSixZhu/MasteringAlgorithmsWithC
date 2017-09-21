//
//  heap.h
//  C
//
//  Created by Mac on 2017/9/14.
//  Copyright © 2017年 oldSix. All rights reserved.
//堆

#ifndef heap_h
#define heap_h

typedef struct Heap_{
    int size;
    int (*compare)(const void *key1,const void *key2);
    void (*destroy)(void *data);
    void **tree;
}Heap;

#include <stdio.h>

void heap_init(Heap *heap,int(*compare)(const void *key1,const void *key2),void(*destroy)(void *data));

void heap_destroy(Heap *heap);
//插入新结点
//注意要重新排序
int heap_insert(Heap *heap,const void *data);
//释放堆顶部结点
//删除顶结点后，把最后一个结点放到顶部然后重新排序
int heap_extract(Heap *heap,void **data);

#define heap_size(heap) ((heap)->size)

#endif /* heap_h */


















