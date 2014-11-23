//
//  main.c
//  PriorityQueue vs Heap
//
//  Created by Bruno Chroniaris on 11/23/14.
//  Copyright (c) 2014 Universidade Federal De Alagoas. All rights reserved.
//

#include "Headers.h"

int main(int argc, const char * argv[])
{
    Hp *hp = NULL;
    int i;
    int value[Max];
    int priority[Max];
    
    for (i = 0; i < Max; i++)
    {
        value[i] = i;
        priority[i] = Max-i;
    }
    
    for (i = 0; i < Max; i++)
    {
        hp = enqueueHp(hp, &value[i], priority[i]);
    }
    
    for (i = 0; i < Max && hp->hpLength > 0; i++)
    {
        int *integer = dequeueHp(hp);
        printf("%d\n", *integer);
    }
    
    return 0;
}
