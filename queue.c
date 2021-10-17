#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int f, r, size;
    int *arr;
};

int isFull(struct queue *q){
    if (q->r == (q->size - 1))
    {
        return 1;
    }
    
    return 0;
}

int isEmpty(struct queue *q){
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int value){
    if (isFull(q))
    {
        printf("!!FULL!!\n");
    }
    q->r++;
    q->arr[q->r] = value;
    printf("Enqueued element = %d\n", value);
}

int dequeue(struct queue *uwu){
    if (isEmpty(uwu))
    {
        printf("!!EMPTY!!\n");
    }
    uwu->f++;
    return uwu->arr[uwu->f];
}

int main(){

    struct queue q;
    q.size = 10;
    q.arr = (int *)malloc(q.size * sizeof(int));
    q.f = q.r = -1;
    
    enqueue(&q, 9);
    enqueue(&q, 11);
    enqueue(&q, 21);
    enqueue(&q, 4);
    enqueue(&q, 1);
    enqueue(&q, 10);

    printf("Dequed element = %d\n",dequeue(&q));
    printf("Dequed element = %d\n",dequeue(&q));

    return 0;
}