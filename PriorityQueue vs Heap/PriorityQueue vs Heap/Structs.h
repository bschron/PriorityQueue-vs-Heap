//
//  Structs.h
//  calendar
//
//  Created by Bruno Chroniaris on 11/5/14.
//  Copyright (c) 2014 UNIUM automação. All rights reserved.
//

#ifndef calendar_Structs_h
#define calendar_Structs_h

#include "Headers.h"

typedef struct hp Hp;
typedef struct priorityQueue PriorityQueue;
typedef struct priorityQueueCapsule PQC;
typedef struct twoWayCapsule TWC;
typedef struct data Data;

struct hp
{
    void *hp[HpSize];
    int priority[HpSize];
    int hpLength;
};

struct priorityQueue
{
    PQC *first;
    int length;
};

struct priorityQueueCapsule
{
    void *object;
    PQC *next;
    int priority;
};

struct twoWayCapsule
{
    void *object;
    TWC *next;
    TWC *previous;
};

struct data
{
    TWC *table[2];
};

#endif
