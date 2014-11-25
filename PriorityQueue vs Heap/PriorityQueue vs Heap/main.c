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
    int dataLength = 100;
    int i;
    void *current = NULL;
    void *currentPriority = NULL;
    
    Data *randomData = enlistRandomData(NULL, NULL, dataLength);
    
    hpEnqueueAccess = 0;
    hpDequeueAcess = 0;
    hpHeapfyAcess = 0;
    priorityQueueEnqueueAccess = 0;
    priorityQueueDequeueAcess = 0;
    
    Hp *hp = NULL;
    PriorityQueue *queue = NULL;
    
    for (current = popObject(&randomData->table[0]), currentPriority = popObject(&randomData->table[1]); currentPriority != NULL && current != NULL; current = popObject(&randomData->table[0]), currentPriority = popObject(&randomData->table[1]))
    {
        hp = enqueueHp(hp, current, *((int*)currentPriority));
        queue = enqueuePriorityQueue(queue, NULL, current, *((int*)currentPriority));
    }
    
    for (current = dequeueHp(hp), currentPriority = dequeuePriorityQueue(queue); current != NULL && currentPriority != NULL; current = dequeueHp(hp), currentPriority = dequeuePriorityQueue(queue));
    
    printf("heapEnqueueAccess = %d heapDequeueAcess = %d heapHeapfyAcess = %d\n queueEnqueueAcess = %d priorityQueueDequeueAcess = %d\n", hpEnqueueAccess, hpDequeueAcess, hpHeapfyAcess, priorityQueueEnqueueAccess, priorityQueueDequeueAcess);
    
    return 0;
}
