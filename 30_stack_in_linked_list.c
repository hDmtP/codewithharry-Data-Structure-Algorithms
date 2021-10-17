#include<stdio.h>
#include<stdlib.h>

//26-07-21

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedlistTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}

int isEmpty(struct Node *top){
    if (top == NULL)
    {
        // printf("!!Empty Linked list warning!!");
        return 1;
    }
    return 0;
}
int isFull(struct Node *top){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        // printf("!!Heap memory Exhaustion warning!!");
        return 1;
    }
    
    return 0;
}



struct Node  *push(struct Node *top, int x){
    if (isFull(top))
    {
        printf("!!Heap memory Exhaustion warning!!\n");
    }
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->next = top;
    top = p;
    return top;
}
//https://www.codewithharry.com/videos/data-structures-and-algorithms-in-hindi-30

int pop(struct Node *tp){
    if (isEmpty(tp))
    {
        printf("!!Heap memory Exhaustion warning!!\n");
    }
    struct Node *p = tp;
    top = tp->next;
    int x = p->data;
    free(p);
    return x;
}


int main(){
    top = push(top, 54);
    top = push(top, 55);
    top = push(top, 56);
    top = push(top, 57);
    linkedlistTraversal(top);
    top = push(top, 69);
    linkedlistTraversal(top);
    int element = pop(top);
    printf("\n popedElement = %d\n", element);
    linkedlistTraversal(top);
    
    return 0;
}