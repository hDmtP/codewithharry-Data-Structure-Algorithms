#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b){
    if(a=='{' && b=='}'){
        return 1;
    }
    else if(a=='(' && b==')'){
        return 1;
    }
    else if(a=='[' && b==']'){
        return 1;
    }
  return 0;  

}

int parenthesisMatch(char * exp, struct stack *sp){
    // Create and initialize the stack :=> "We dont do that here ( ͡° ͜ʖ ͡°)"

    char poped_ch;

    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp, exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp)){
                return 0;
            }
            poped_ch = pop(sp); 
            if (!match(poped_ch, exp[i]))
            {
                return 0;
            }
            
        }
    }

    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main()
{
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    
    // char * exp = "((8)(*--$$9)))))()(";
    char * exp = "( ͡° ͜ʖ ͡°)}";
    // Check if stack is empty
    if(parenthesisMatch(exp, sp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}