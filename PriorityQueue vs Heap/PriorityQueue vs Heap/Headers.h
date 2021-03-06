//
//  Headers.h
//  calendar
//
//  Created by Bruno Chroniaris on 11/5/14.
//  Copyright (c) 2014 UNIUM automação. All rights reserved.
//

#ifndef calendar_Headers_h
#define calendar_Headers_h

#define Max 100
#define description 300
#define SearchTableSize 661
#define not_in_use -1
#define HpSize 1000000
#define MainDir "/Documents/spyridonsCalendar"
#define MainCalendar "calendar"
#define CalendarFileExtension ".spyridon"
#define SearchingLimit 1000
#define NumberOfRecurrences 31

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mach/mach_time.h>
#include <time.h>
#include <sys/time.h>

#include "Structs.h"

long long int hpHeapfyAcess, hpEnqueueAccess, hpDequeueAcess;
long long int priorityQueueEnqueueAccess, priorityQueueDequeueAcess;
long long int _individualHpHeapfyAcess[5], _individualHpEnqueueAccess[5], _individualHpDequeueAcess[5];
long long int _individualPriorityQueueEnqueueAccess[5], _individualPriorityQueueDequeueAcess[5];
int loadingIc;
int delay;
int cases[5];

#include "Heap.h"
#include "Object Priority Queue.h"
#include "Object List.h"
#include "Suport Functions.h"
#include "Exporting Module.h"

#endif
