//
//  Exporting Module.c
//  PriorityQueue vs Heap
//
//  Created by Bruno Chroniaris on 11/25/14.
//  Copyright (c) 2014 Universidade Federal De Alagoas. All rights reserved.
//

#include "Exporting Module.h"

void export (void)
{
    char *home = getenv("HOME");//path to home folder
    char output[Max];
    char heapIn[Max];
    char heapOut[Max];
    char heapfy[Max];
    char xAxis[Max];
    char queueIn[Max];
    char queueOut[Max];
    char diffIn[Max];
    char diffOut[Max];
    char inRange[Max];
    char outRange[Max];
    char diffRange[Max];
    char heapfyRange[Max];
    
    snprintf(output, sizeof(output)/sizeof(char), "%s/Desktop/R_graphs.txt", home);
    
    FILE *file = fopen(output, "w");
    
    sprintf(heapIn, "heapIn<-c(%d,%d,%d,%d,%d);", _10hpEnqueueAccess, _100hpEnqueueAccess, _1000hpEnqueueAccess, _10000hpEnqueueAccess, _100000hpEnqueueAccess);
    sprintf(heapOut, "heapOut<-c(%d,%d,%d,%d,%d);", _10hpDequeueAcess, _100hpDequeueAcess, _1000hpDequeueAcess, _10000hpDequeueAcess, _100000priorityQueueDequeueAcess);
    sprintf(heapfy, "heapfy<-c(%d,%d,%d,%d,%d);", _10hpHeapfyAcess, _100hpHeapfyAcess, _1000hpHeapfyAcess, _10000hpHeapfyAcess, _100000hpHeapfyAcess);
    sprintf(xAxis, "xAxis<-c(10,100,1000,10000,100000);");
    sprintf(queueIn, "queueIn<-c(");
    
    fclose(file);
}