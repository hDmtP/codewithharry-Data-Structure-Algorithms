#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
    // struct stack *arr;
};

int isEmpty(struct stack * ptr)
{
    if (ptr->top == -1)
    {
        return 1; // this means TRUE
    }
    return 0;   //this means FALSE
}

int isFull(struct stack *ptr){
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    return 0;   
}

void push(struct stack *ptr, int val){
    if (isFull(ptr))
    {
        printf("Stack Overflowed!!");
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
    
}

int pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("Stack is Underflowed!!");
        return -1;
    }
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int main(){
    struct stack * sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("%d\n", isFull(sp));
    printf("%d\n", isEmpty(sp));
    
    push(sp, 69);
    push(sp, 420);
    push(sp, 666);

    printf("%d\n", sp->arr[sp->top]);
    pop(sp);
    pop(sp);

    printf("%d\n", isFull(sp));
    printf("%d\n", isEmpty(sp));

    printf("%d\n", sp->arr[sp->top]);
    
    return 0;
}