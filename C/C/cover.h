//
//  cover.h
//  C
//
//  Created by Mac on 2017/8/21.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#ifndef cover_h
#define cover_h

#include <stdio.h>
#include "set.h"

typedef struct KSet_{
    void *key;
    Set set;
}KSet;

int cover(Set *members,Set *subsets,Set *covering);

#endif /* cover_h */
