#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack s)
{
    if (s.top == -1)
    {
        return 1; // this means TRUE
    }
    return 0;   //this means FALSE
}

int isFull(struct stack s){
    if (s.top == (s.size - 1))
    {
        return 1;
    }
    return 0;   
}

int main(){
    
    struct stack s1;
    s1.size = 6;
    s1.top = -1;
    s1.arr = (int *)malloc(s1.size * sizeof(int));
    for (int i = 0; i < s1.size; i++)
    {
        printf("enter the %d th element:\n", i);
        s1.arr[i] = scanf("%d", &s1.arr[i]);
        s1.top++;
    }
    
    if (isFull(s1))
    {
        printf("Stack is full i.e. s1.top=%d", s1.top);
    }
    else
    {
        printf("Stack is not full yet. s1.top=%d", s1.top);
    }
    

    return 0;
}