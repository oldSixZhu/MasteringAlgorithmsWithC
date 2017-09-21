//
//  bistree.h
//  C
//
//  Created by Mac on 2017/9/7.
//  Copyright © 2017年 oldSix. All rights reserved.
//二叉搜索树

#ifndef bistree_h
#define bistree_h

#include <stdio.h>
#include "bitree.h"

#define AVL_LFT         1
#define AVL_BALANCED    0
#define AVL_RGT_HEAVY  -1

typedef struct AvlNode_{
    void *data;
    int hidden;
    int factor;
}AvlNode;

typedef BiTree BisTree;

void bistree_init(BisTree *tree,int(*compare)(const void *key1,const void *key2),void(*destroy)(void *data));
void bistree_destroy(BisTree *tree);
int bistree_insert(BisTree *tree,const void *data);
int bistree_remove(BisTree *tree,const void *data);
int bistree_lookup(BisTree *tree,void **data);

#define bistree_size(tree) ((tree)->size)

#endif /* bistree_h */

























