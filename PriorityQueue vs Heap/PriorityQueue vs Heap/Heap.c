//
//  Searching Hp.c
//  Calendar
//
//  Created by Bruno Chroniaris on 11/6/14.
//  Copyright (c) 2014 Universidade Federal De Alagoas. All rights reserved.
//

#include "Heap.h"

int hpParent (int child)
{
    if (child == 0)
    {
        return -1;
    }
    else if (child%2 == 0)
    {
        return (child/2)-1;
    }
    else
    {
        return child/2;
    }
}

int hpLeftChild (int parent)
{
    return (parent*2) +1;
}

int hpRightChild (int parent)
{
    return (parent*2) +2;
}

Hp* createEmptyHp (void)
{
    Hp *new = (Hp*) malloc(sizeof(Hp));
    
    initializeHp(new);
    
    return new;
}

int peekHpHighestPriority (Hp *hp)
{
    if (hp == NULL)
    {
        return -1;
    }
    else if (hp->hpLength == 0)
    {
        return -1;
    }
    
    return hp->priority[0];
}

void hpfyHp (Hp *hp, int parent)
{
    if (parent < 0 || hp == NULL || parent > HpSize-1)
    {
        return;
    }
    else if (hp->hp[parent] == NULL)
    {
        return;
    }
    else if (parent != 0)
    {
        int parentParent = hpParent(parent);
        
        if (hp->priority[parent] > hp->priority[parentParent])
        {
            hpfyHp(hp, parentParent);
        }
    }
    
    int leftChild = hpLeftChild(parent);
    int rightChild = hpRightChild(parent);
    //flagging child as invalid.
    if (hp->hp[leftChild] == NULL || leftChild >= HpSize)
    {
        leftChild = -1;
    }
    if (hp->hp[rightChild] == NULL || rightChild >= HpSize)
    {
        rightChild = -1;
    }
    int biggestChild = maxHpChild(hp, leftChild, rightChild);
    
    if (hp->hp[biggestChild] != NULL && hp->priority[parent] < hp->priority[biggestChild] && hp->priority[biggestChild] != -1)
    {
        hpHeapfyAcess++;
        loadingIcon(&loadingIc);
        
        switchHpItems(hp, parent, biggestChild);
        hpfyHp(hp, biggestChild);
        hpfyHp(hp, parent);
    }
    
    return;
}

void switchHpItems (Hp *hp, int item1, int item2)
{
    int transitionInt;
    void *transitionObject;
    
    transitionObject = hp->hp[item1];
    transitionInt = hp->priority[item1];
    
    hp->hp[item1] = hp->hp[item2];
    hp->priority[item1] = hp->priority[item2];
    
    hp->hp[item2] = transitionObject;
    hp->priority[item2] = transitionInt;
}

Hp* enqueueHp (Hp *hp, void *object, int priority)
{
    if (object == NULL)
    {
        return hp;
    }
    else if (hp == NULL)
    {
        return enqueueHp(createEmptyHp(), object, priority);
    }
    
    if (hp->hpLength < HpSize)
    {
        hpEnqueueAccess++;
        loadingIcon(&loadingIc);
        
        hp->hp[hp->hpLength] = object;
        hp->priority[hp->hpLength] = priority;
        hpfyHp(hp, hp->hpLength);
        (hp->hpLength)++;
    }
    
    return hp;
}

void initializeHp (Hp *hp)

{
    int i;
    
    for (i=0; i<HpSize; i++)
    {
        hp->hp[i] = NULL;
        hp->priority[i] = -1;
    }
    
    hp->hpLength = 0;
}

void* dequeueHp (Hp *hp)
{
    if (hp == NULL)
    {
        return NULL;
    }
    else if (hp->hpLength <= 0)
    {
        return NULL;
    }
    
    //get first
    void *dequeued = hp->hp[0];
    
    //replace first with last
    hp->hp[0] = hp->hp[hp->hpLength-1];
    hp->priority[0] = hp->priority[hp->hpLength-1];
    //remove last
    hp->hp[hp->hpLength-1] = NULL;
    hp->priority[hp->hpLength-1] = -1;
    //decrease hp length
    (hp->hpLength)--;
    
    //hpfy
    hpfyHp(hp, 0);
    
    hpDequeueAcess++;
    
    //return dequeued
    return dequeued;
}

int maxHpChild (Hp *hp, int left, int right)
{
    if (hp->priority[left] > hp->priority[right])
    {
        return left;
    }
    else
    {
        return right;
    }
}

Hp* duplicateHp (Hp *hp)
{
    if (hp == NULL)
    {
        return NULL;
    }
    
    Hp *new = createEmptyHp();
    
    int i;
    for (i = 0; i<hp->hpLength; i++)
    {
        new->hp[i] = hp->hp[i];
        new->priority[i] = hp->priority[i];
    }
    new->hpLength = hp->hpLength;
    
    return new;
}