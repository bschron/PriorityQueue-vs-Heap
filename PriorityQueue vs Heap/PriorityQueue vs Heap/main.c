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
    int dataLength = 666;
    int i;
    void *current = NULL;
    void *currentPriority = NULL;
    
    Data *randomData = enlistRandomData(NULL, NULL, dataLength);
    
    hpEnqueueAccess = 0;
    hpDequeueAcess = 0;
    hpHeapfyAcess = 0;
    priorityQueueEnqueueAccess = 0;
    priorityQueueDequeueAcess = 0;
    
    for (dataLength = 10, i = 0; dataLength <= 100000 && i<5; dataLength *= 10, hpEnqueueAccess = 0, hpDequeueAcess = 0, priorityQueueEnqueueAccess = 0, priorityQueueDequeueAcess = 0, hpHeapfyAcess = 0, i++)
    {
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
        
        free(hp);
        hp = NULL;
        freePriorityQueue(&queue);
        
        _individualHpDequeueAcess[i] = hpDequeueAcess;
        _individualHpEnqueueAccess[i] = hpEnqueueAccess;
        _individualHpHeapfyAcess[i] = hpHeapfyAcess;
        _individualPriorityQueueDequeueAcess[i] = priorityQueueDequeueAcess;
        _individualPriorityQueueEnqueueAccess[i] = priorityQueueEnqueueAccess;
        
        printf("heapEnqueueAccess = %lld heapDequeueAcess = %lld heapHeapfyAcess = %lld\n queueEnqueueAcess = %lld priorityQueueDequeueAcess = %lld\n\n", hpEnqueueAccess, hpDequeueAcess, hpHeapfyAcess, priorityQueueEnqueueAccess, priorityQueueDequeueAcess);
    }
    
    export();
    
    return 0;
}
