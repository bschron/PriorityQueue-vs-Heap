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

int hpHeapfyAcess, hpEnqueueAccess, hpDequeueAcess;
int priorityQueueEnqueueAccess, priorityQueueDequeueAcess;
int _10hpHeapfyAcess, _10hpEnqueueAccess, _10hpDequeueAcess;
int _10priorityQueueEnqueueAccess, _10priorityQueueDequeueAcess;
int _100hpHeapfyAcess, _100hpEnqueueAccess, _100hpDequeueAcess;
int _100priorityQueueEnqueueAccess, _100priorityQueueDequeueAcess;
int _1000hpHeapfyAcess, _1000hpEnqueueAccess, _1000hpDequeueAcess;
int _1000priorityQueueEnqueueAccess, _1000priorityQueueDequeueAcess;
int _10000hpHeapfyAcess, _10000hpEnqueueAccess, _10000hpDequeueAcess;
int _10000priorityQueueEnqueueAccess, _10000priorityQueueDequeueAcess;
int _100000hpHeapfyAcess, _100000hpEnqueueAccess, _100000hpDequeueAcess;
int _100000priorityQueueEnqueueAccess, _100000priorityQueueDequeueAcess;

#include "Heap.h"
#include "Object Priority Queue.h"
#include "Object List.h"
#include "Suport Functions.h"
#include "Exporting Module.h"

#endif
