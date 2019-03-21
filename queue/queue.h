#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct
{
    int capacity;
    int front;
    int rear;
    int size;
    int *dataList;
}Queue, *PQueue;

PQueue CreateQueue(int size);
int IsEmpty(PQueue q);
int isFull(PQueue q);
void DisposeQueue(PQueue q);
void MakeEmpty(PQueue q);
void Enqueue(int value, PQueue q);
void Dequeue(PQueue q);
int Front(PQueue q);
int FrontAndDequeue(PQueue q);


#endif