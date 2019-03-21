#include <stdio.h>
#include "queue.h"

#define QUEUE_SIZE  7

int main(int argc, char* argv[])
{
    int i, j;
    int data = 0;
    PQueue q = CreateQueue(QUEUE_SIZE);

    if (IsEmpty(q) == 0)
        printf("empty\n");

    for (i = 0; i < QUEUE_SIZE - 2; i++)
    {
        Enqueue(i+1, q);
        printf("Enqueue[%d]         => ", i+1);
        for (j = 0; j < q->capacity; j++)
        {
            printf("%d ", q->dataList[j]);
        }
        printf(" || front[%d] rear[%d] size[%d]\n",
                q->front,
                q->rear,
                q->size);
    }

    
    for (i = 0; i < QUEUE_SIZE; i++)
    {
        data = FrontAndDequeue(q);
        printf("frontAndDequeue[%d] || ", data);
        for (j = 0; j < q->capacity; j++)
        {
            printf("%d ", q->dataList[j]);
        }
        printf(" || front[%d] rear[%d] size[%d]\n",
            q->front,
            q->rear,
            q->size);
    }
    
    for (i = 0; i < QUEUE_SIZE - 2; i++)
    {
        Enqueue(i+1, q);
        printf("Enqueue[%d]         => ", i+1);
        for (j = 0; j < q->capacity; j++)
        {
            printf("%d ", q->dataList[j]);
        }
        printf(" || front[%d] rear[%d] size[%d]\n",
                q->front,
                q->rear,
                q->size);
    }    



    return 0;
}