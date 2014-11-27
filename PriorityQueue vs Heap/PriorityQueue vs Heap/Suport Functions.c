//
//  Suport Functions.c
//  PriorityQueue vs Heap
//
//  Created by Bruno Chroniaris on 11/24/14.
//  Copyright (c) 2014 Universidade Federal De Alagoas. All rights reserved.
//

#include "Suport Functions.h"

Data* enlistRandomData (Data* data, int *seed, int dataLength)
{
    if (data == NULL)
    {
        data = (Data*) malloc(sizeof(Data));
        data->table[0] = NULL;
        data->table[1] = NULL;
        return enlistRandomData(data, seed, dataLength);
    }
    else if (dataLength <= 0)
    {
        return data;
    }
    else if (seed == NULL)
    {
        seed = (int*) malloc(sizeof(int));
        *seed = (int) rand();
        return enlistRandomData(data, seed, dataLength);
    }
    else if (*seed == -1 || *seed == 1 || (*seed >= -1 && *seed <= 1))
    {
        *seed = 2;
        return enlistRandomData(data, seed, dataLength);
    }
    
    data->table[0] = insertTWC(data->table[0], createTWC(seed));
    seed = (int*) malloc(sizeof(int));
    
    *seed = rand();
    
    data->table[1] = insertTWC(data->table[1], createTWC(seed));
    
    if (dataLength > 1)
    {
        seed = (int*) malloc(sizeof(int));
        *seed = rand();
    }
    else
    {
        seed = NULL;
    }
    
    return enlistRandomData(data, seed, dataLength-1);
}

int max (int one, int two)
{
    int maximum;
    
    if (one > two)
    {
        maximum = one;
    }
    else
    {
        maximum = two;
    }
    
    return maximum;
}

int min (int one, int two)
{
    int minimum;
    
    if (one < two)
    {
        minimum = one;
    }
    else
    {
        minimum = two;
    }
    
    return minimum;
}