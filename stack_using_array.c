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

int main(){
    /*
    struct stack s1;
    s1.size = 80;
    s1.top = -1; //"-1" means the stack is empty
    // s1.arr = (struct stack *)malloc(s1.size * sizeof(int));
    s1.arr = (int *)malloc(s1.size * sizeof(int));
    */

   struct stack *s;
   s->size = 80;
   s->top = -1;
   s->arr = (int *)malloc(s->size * sizeof(int));

   s->arr[0] = 69;
   s->top++;

   //check if the  stack is empty
   if(isEmpty(s))
   {
       printf("Stack is empty");
   }
   else
   {
       printf("stack is not empty");
   }
    return 0;
}