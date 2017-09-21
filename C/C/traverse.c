//
//  traverse.c
//  C
//
//  Created by Mac on 2017/9/19.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#include "traverse.h"
#include "list.h"
#include "bitree.h"

//前序
int preorderTraverse(const BiTreeNode *node,List *list)
{
    if (!bitree_is_eob(node))
    {
        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
        {
            return -1;
        }
        
        if (!bitree_is_eob(bitree_left(node)))
        {
            if (preorderTraverse(bitree_left(node), list) != 0)
            {
                return -1;
            }
            
            if (!bitree_is_eob(bitree_right(node)))
            {
                if (preorderTraverse(bitree_right(node), list) != 0)
                {
                    return -1;
                }
            }
        }
    }
    return 0;
}

//中序
int inorderTraverse(const BiTreeNode *node,List *list)
{
    if (!bitree_is_eob(node))
    {
        if (!bitree_is_eob(bitree_left(node)))
        {
            if (inorderTraverse(bitree_left(node), list) != 0)
            {
                return -1;
            }
        }
        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
        {
            return -1;
        }
        if (!bitree_is_eob(bitree_right(node)))
        {
            if (inorderTraverse(bitree_right(node), list) != 0)
            {
                return -1;
            }
        }
    }
    return 0;
}

//后序
int postorderTraverse(const BiTreeNode *node,List *list)
{
    if (!bitree_is_eob(node))
    {
        if (!bitree_is_eob(bitree_left(node)))
        {
            if (postorderTraverse(bitree_left(node), list) != 0)
            {
                return -1;
            }
        }
        if (!bitree_is_eob(bitree_right(node)))
        {
            if (postorderTraverse(bitree_right(node), list) != 0)
            {
                return -1;
            }
        }
        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
        {
            return -1;
        }
    }
    return 0;
}


























