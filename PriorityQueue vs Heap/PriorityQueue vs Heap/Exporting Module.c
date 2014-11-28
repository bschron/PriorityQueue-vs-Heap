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
    char yAxis[Max];
    
    snprintf(output, sizeof(output)/sizeof(char), "%s/Desktop/R_graphs.txt", home);
    
    FILE *file = fopen(output, "w");
    
    //heapIn
    sprintf(heapIn, "heapIn<-c(%lld,%lld,%lld,%lld,%lld);", _individualHpEnqueueAccess[0], _individualHpEnqueueAccess[1], _individualHpEnqueueAccess[2], _individualHpEnqueueAccess[3], _individualHpEnqueueAccess[4]);
    //heapOut
    sprintf(heapOut, "heapOut<-c(%lld,%lld,%lld,%lld,%lld);", _individualHpDequeueAcess[0], _individualHpDequeueAcess[1], _individualHpDequeueAcess[2], _individualHpDequeueAcess[3], _individualHpDequeueAcess[4]);
    //heapfy
    sprintf(heapfy, "heapfy<-c(%lld,%lld,%lld,%lld,%lld);", _individualHpHeapfyAcess[0], _individualHpHeapfyAcess[1], _individualHpHeapfyAcess[2], _individualHpHeapfyAcess[3], _individualHpHeapfyAcess[4]);
    //xAxis
    sprintf(xAxis, "xAxis<-c(10,100,1000,10000,100000);");
    //queueIn
    sprintf(queueIn, "queueIn<-c(%lld,%lld,%lld,%lld,%lld);", _individualPriorityQueueEnqueueAccess[0], _individualPriorityQueueEnqueueAccess[1], _individualPriorityQueueEnqueueAccess[2], _individualPriorityQueueEnqueueAccess[3], _individualPriorityQueueEnqueueAccess[4]);
    //queueOut
    sprintf(queueOut, "queueOut<-c(%lld,%lld,%lld,%lld,%lld);", _individualPriorityQueueDequeueAcess[0], _individualPriorityQueueDequeueAcess[1], _individualPriorityQueueDequeueAcess[2], _individualPriorityQueueDequeueAcess[3], _individualPriorityQueueDequeueAcess[4]);
    //diffIn
    long long int diff10 = _individualPriorityQueueEnqueueAccess[0] - _individualHpEnqueueAccess[0] + _individualHpHeapfyAcess[0];
    long long int diff100 = _individualPriorityQueueEnqueueAccess[1] - _individualHpEnqueueAccess[1] + _individualHpHeapfyAcess[1];
    long long int diff1000 = _individualPriorityQueueEnqueueAccess[2] - _individualHpEnqueueAccess[2] + _individualHpHeapfyAcess[2];
    long long int diff10000 = _individualPriorityQueueEnqueueAccess[3] - _individualHpEnqueueAccess[3] + _individualHpHeapfyAcess[3];
    long long int diff100000 = _individualPriorityQueueEnqueueAccess[4] - _individualHpEnqueueAccess[4] + _individualHpHeapfyAcess[4];
    sprintf(diffIn, "diffIn<-c(%lld,%lld,%lld,%lld,%lld);", diff10, diff100, diff1000, diff10000, diff100000);
    //diffOut
    diff10 = _individualPriorityQueueDequeueAcess[0] - _individualHpDequeueAcess[0];
    diff100 = _individualPriorityQueueDequeueAcess[1] - _individualHpDequeueAcess[1];
    diff1000 = _individualPriorityQueueDequeueAcess[2] - _individualHpDequeueAcess[2];
    diff10000 = _individualPriorityQueueDequeueAcess[3] - _individualHpDequeueAcess[3];
    diff100000 = _individualPriorityQueueDequeueAcess[4] - _individualHpDequeueAcess[4];
    sprintf(diffOut, "diffOut<-c(%lld,%lld,%lld,%lld,%lld);", diff10, diff100, diff1000, diff10000, diff100000);
    //inRange
    sprintf(inRange, "inRange<-range(0, heapIn, queueIn);");
    //outRange
    sprintf(outRange, "outRange<-range(0, heapOut, queueOut);");
    //diffRange
    sprintf(diffRange, "diffRange<-range(0, diffIn, diffOut);");
    //heapfyRange
    sprintf(heapfyRange, "heapfyRange<-range(0,heapfy);");
    
    //objects definition
    char objects[Max*20];
    sprintf(objects, "%s%s%s%s%s%s%s%s%s%s%s%s", heapIn, heapOut, heapfy, xAxis, queueIn, queueOut, diffIn, diffOut, inRange, outRange, diffRange, heapfyRange);
    
    //enqueue graph
    char enqueuePlot[Max];
    sprintf(enqueuePlot, "plot(heapIn,type=%co%c,col=%cblue%c,ylim=inRange,ann=FALSE,axes=FALSE);", 34, 34, 34, 34);
    char enqueueTitle[Max*3];
    sprintf(enqueueTitle, "title(main=%cEnqueueing%c,col.main=%cblack%c,font.main=4);title(xlab=%cnumber of objects%c,col.lab=rgb(0,0.5,0));title(ylab=%cn of processes%c,col.lab=rgb(0,0.5,0));", 34, 34, 34, 34, 34, 34, 34, 34);
    char enqueueLines[Max];
    sprintf(enqueueLines, "lines(queueIn,type=%co%c,pch=22,lty=2,col=%cred%c);", 34, 34, 34, 34);
    char enqueueAxis[Max];
    sprintf(enqueueAxis, "axis(1,at=1:5,lab=xAxis);axis(2,las=1,at=inRange);");
    char enqueueLegend[Max];
    sprintf(enqueueLegend, "legend(1,inRange[2],c(%cheap%c,%cqueue%c),cex=0.8,col=c(%cblue%c,%cred%c),pch=21:22,lty=1:2);", 34, 34, 34, 34, 34, 34, 34, 34);
    char enqueueGraph[Max*20+(sizeof(objects)/sizeof(char))];
    sprintf(enqueueGraph, "%s%s%s%s%s%sbox();", objects, enqueuePlot, enqueueTitle, enqueueLines, enqueueAxis, enqueueLegend);
    
    fprintf(file, "%s\n", enqueueGraph);
    
    //dequeue graph
    char dequeuePlot[Max];
    sprintf(dequeuePlot, "plot(heapOut,type=%co%c,col=%cblue%c,ylim=outRange,ann=FALSE,axes=FALSE);",34, 34, 34, 34);
    char dequeueTitle[Max*3];
    sprintf(dequeueTitle, "title(main=%cdequeueing%c,col.main=%cblack%c,font.main=4);title(xlab=%cnumber of objects%c,col.lab=rgb(0,0.5,0));title(ylab=%cnumber of processes%c,col.lab=rgb(0,0.5,0));", 34, 34, 34, 34, 34, 34, 34, 34);
    char dequeueLines[Max];
    sprintf(dequeueLines, "lines(queueOut,type=%co%c,pch=22,lty=2,col=%cred%c);", 34, 34, 34, 34);
    char dequeueAxis[Max];
    sprintf(dequeueAxis, "axis(1,at=1:5,lab=xAxis);axis(2,las=1,at=outRange);");
    char dequeueLegend[Max];
    sprintf(dequeueLegend, "legend(1,outRange[2],c(%cheap%c,%cqueue%c),cex=0.8,col=c(%cblue%c,%cred%c),pch=21:22,lty=1:2);", 34, 34, 34, 34, 34, 34, 34, 34);
    char dequeueGraph[Max*20+(sizeof(objects)/sizeof(char))];
    sprintf(dequeueGraph, "%s%s%s%s%s%sbox()", objects, dequeuePlot, dequeueTitle, dequeueLines, dequeueAxis, dequeueLegend);
    
    fprintf(file, "%s\n", dequeueGraph);
    
    //heapfy graph
    char heapfyPlot[Max];
    sprintf(heapfyPlot, "plot(heapfy,type=%co%c,col=%cgreen%c,ylim=heapfyRange,ann=FALSE,axes=FALSE);", 34, 34, 34, 34);
    char heapfyTitle[Max*3];
    sprintf(heapfyTitle, "title(main=%cHeapfy%c,col.main=%cblack%c,font.main=4);title(xlab=%cnumber of objects%c,col.lab=rgb(0,0.5,0));title(ylab=%cnumber of processes%c,col.lab=rgb(0,0.5,0));", 34, 34, 34, 34, 34, 34, 34, 34);
    char heapfyAxis[Max];
    sprintf(heapfyAxis, "axis(1,at=1:5,lab=xAxis);axis(2,las=1,at=heapfyRange);");
    char heapfyGraph[Max*10+(sizeof(objects)/sizeof(char))];
    sprintf(heapfyGraph, "%s%s%s%sbox();", objects, heapfyPlot, heapfyTitle, heapfyAxis);
    
    fprintf(file, "%s\n", heapfyGraph);
    
    //diff graph
    char diffPlot[Max];
    sprintf(diffPlot, "plot(diffIn,type=%co%c,col=%cblue%c,ylim=diffRange,ann=FALSE,axes=FALSE);",34, 34, 34, 34);
    char diffTitle[Max*3];
    sprintf(diffTitle, "title(main=%cheap advantage%c,col.main=%cblack%c,font.main=4);title(xlab=%cnumber of objects%c,col.lab=rgb(0,0.5,0));title(ylab=%cprocesses advantage%c,col.lab=rgb(0,0.5,0));", 34, 34, 34, 34, 34, 34, 34, 34);
    char diffAxis[Max];
    sprintf(diffAxis, "axis(1,at=1:5,lab=xAxis);axis(2,las=1,at=diffRange);");
    char diffGraph[Max*10+(sizeof(objects)/sizeof(char))];
    sprintf(diffGraph, "%s%s%s%sbox();", objects, diffPlot, diffTitle, diffAxis);
    
    fprintf(file, "%s\n", diffGraph);
    
    fclose(file);
}