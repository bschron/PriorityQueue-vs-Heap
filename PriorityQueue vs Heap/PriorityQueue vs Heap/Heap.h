//
//  Searching Hp.h
//  Calendar
//
//  Created by Bruno Chroniaris on 11/6/14.
//  Copyright (c) 2014 Universidade Federal De Alagoas. All rights reserved.
//

#ifndef __Calendar__Searching_Hp__
#define __Calendar__Searching_Hp__

#include "Headers.h"

/*returns the value of the node parend one a hp, will return -1 if it's root*/
int hpParent (int child);
/*returns the valie of the node left child*/
int hpLeftChild (int parent);
/*returns the valie of the node right child*/
int hpRightChild (int parent);
/*returns a pointer to a new Hp with empty values and flags*/
Hp* createEmptyHp (void);
/*sets all pointer values to NULL and priority values to -1, and length to 0*/
void initializeHp (Hp *hp);
/*enqueues event on the Hp and calls hpfy, but if it already exists, will increase it's priority instead and calls hpdy*/
Hp* enqueueHp (Hp *hp, void *object, int priority);
/*requires a pointer to the hp and the positon of the root or sub-root from wich will start the function*/
void hpfyHp (Hp *hp, int parent);
/*given two searching hp positions and a pointer to the hp, will switch the positions of the value and priorities of each item*/
void switchHpItems (Hp *hp, int item1, int item2);
/*will deque the biggest element from the provided hp, hpfy the tree, and return the dequeued element. If the hp is empty or NULL, will return NULL*/
void* dequeueHp (Hp *hp);
/*requests the two SearchingHeap Childs and returns the one with biggest priority*/
int maxHpChild (Hp *hp, int left, int right);
/*will return the priority of the highest priority element on that heap. WIll return -1 if heap is NULL or if heap size is 0*/
int peekHpHighestPriority (Hp *hp);
/*takes a pointer to a Hp as argument, returns a pointer to a new Searching heap with the same values as the provided SearchingHeap. if the provided pointer is NULL, returns NULL*/
Hp* duplicateHp (Hp *hp);

#endif /* defined(__Calendar__Searching_Hp__) */
