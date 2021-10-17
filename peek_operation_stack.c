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

//23-07-2021

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

//24-07-2021

int peek(struct stack *ptr, int i){
    int arrId = ptr->top -i + 1;
    if (arrId < 0)
    {
        printf("Not a Valid position");
        return -1;
    }
    return ptr->arr[arrId];
}

int main(){
    struct stack * sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    
    push(sp, 69);
    push(sp, 420);
    push(sp, 666);
    push(sp, 645);
    push(sp, 466);

    printf("%d\n",peek(sp, 3));
    for (int i = 1; i <= (sp->top + 1); i++)
    {
        printf("%d\n",peek(sp, i));
    }
    

    return 0;
}