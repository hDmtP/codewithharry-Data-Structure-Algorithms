#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
    int f, r, size;
    int *arr;
};

int isFull(struct circularQueue *q){
    if (q->r+1 % (q->size) == q->f)
    {
        return 1;
    }
    
    return 0;
}

int isEmpty(struct circularQueue *q){
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int value){
    if (isFull(q))
    {
        printf("!!FULL!!\n");
    }
    q->r = (q->r+1)%q->size;
    q->arr[q->r] = value;
    printf("Enqueued element = %d\n", value);
}

int dequeue(struct circularQueue *uwu){
    int a = -1;
    if (isEmpty(uwu))
    {
        printf("!!EMPTY!!\n");
    }
    uwu->f = (uwu->f+1)%uwu->size;
    a = uwu->arr[uwu->f];
    return a;
}

int main(){

    struct circularQueue q;
    q.size = 10;
    q.arr = (int *)malloc(q.size * sizeof(int));
    q.f = q.r = -1;
    
    enqueue(&q, 9);
    enqueue(&q, 11);
    enqueue(&q, 21);
    enqueue(&q, 4);
    enqueue(&q, 1);
    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 14);
    enqueue(&q, 15);
    enqueue(&q, 16);
    enqueue(&q, 69);

    printf("Dequed element = %d\n",dequeue(&q));
    printf("Dequed element = %d\n",dequeue(&q));

    return 0;
}