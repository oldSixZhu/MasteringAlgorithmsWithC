//
//  page.h
//  C
//
//  Created by Mac on 2017/8/11.
//  Copyright © 2017年 oldSix. All rights reserved.
//
//第二次机会页面置换法

#ifndef page_h
#define page_h

#include <stdio.h>
#include "clist.h"


typedef struct Page_{
    int number;
    int reference;
}Page;

int replace_page(CListElmt **current);

#endif /* page_h */
