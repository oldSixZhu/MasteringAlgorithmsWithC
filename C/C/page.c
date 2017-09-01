//
//  page.c
//  C
//
//  Created by Mac on 2017/8/11.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#include "page.h"

int replace_page(CListElmt **current)
{
    while (((Page *)(*current)->data)->reference != 0)
    {
        ((Page *)(*current)->data)->reference = 0;
        *current = clist_next(*current);
    }
    return ((Page *)(*current)->data)->number;
}
