#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

PQueue CreateQueue(int size)
{
    PQueue q = (PQueue)malloc(sizeof(Queue));
    q->capacity = size;
    q->dataList = (int*)malloc(sizeof(int) * size);
    memset(q->dataList, 0, sizeof(int) * size);
printf("CreateQueue || front[%d] rear[%d] size[%d] capacity[%d]\n",
        q->front,
        q->rear,
        q->size,
        q->capacity);
    return q;
}

int IsEmpty(PQueue q)
{
    return q->size == 0;
}

int isFull(PQueue q)
{
    return q->size == q->capacity;
}

void Enqueue(int value, PQueue q)
{
    q->dataList[q->rear] = value;
    if (q->size < q->capacity)
    {
        q->rear = (q->rear + 1) % q->capacity;
        q->size++;
    }
    else
    {
        printf("Out of space\n");
    }
}

void Dequeue(PQueue q)
{
    if (q->front != q->rear)
    {
        q->dataList[q->front] = 0;
        q->front = (q->front + 1) % q->capacity;
        q->size--;
    }
    else
    {
        printf("queue is empty. could not dequeue.\n");
    }
}

int Front(PQueue q)
{
    return q->dataList[q->front];
}

int FrontAndDequeue(PQueue q)
{
    int ret = Front(q);
    ret = q->dataList[q->front];
    Dequeue(q);
    return ret;
}