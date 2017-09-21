//
//  main.c
//  C
//
//  Created by Mac on 2017/8/10.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#include <stdio.h>
#include "issort.h"
#include "qksort.h"
#include "mgsort.h"
#include "ctsort.h"
#include "rxsort.h"

int main(int argc, const char * argv[]) {
    
//    int a[10] = {0,2,1,3,5,7,9,8,6,4};
    int a[10] = {12,14,11,15,2,17,19,18,16,1};
    
//    int result = issort(a, 10, sizeof(int), compare);
    
//    int result = qksort(a, 10, sizeof(int), 0, 9, compare);
    
//    int result = mgsort(a, 10, sizeof(int), 0, 9, compare);

//    int result = ctsort(a, 10, 10);
    
    int result = rxsort(a,10, 2, 10);
    
    printf("%d\n",result);
    for (int i=0; i<10; i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}

int compare(const void *key1,const void *key2)
{
    if (*(int *)key1 > *(int *)key2) {
        return 1;
    }
    else if (*(int *)key1 == *(int *)key2){
        return 0;
    }
    else{
        return -1;
    }
}




