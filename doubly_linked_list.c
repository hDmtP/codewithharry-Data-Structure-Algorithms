#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

void push(struct node** head, int new_data)
{
    struct node* new_node
        = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head);
    new_node->prev = NULL;

    if ((*head) != NULL)
    {
        (*head)->prev = new_node;
    }
    (*head) = new_node;
    
}

void pushBefore(struct node** head, struct node* next_node,
       int new_data)
{
    if (next_node == NULL)
    {
        return;
    }
    struct node* new_node
            = (struct node*)malloc(sizeof(struct node));
    
    new_node->data = new_data;
    new_node->prev = next_node->prev;
    next_node->prev = new_node;
    new_node->next = next_node;

    if (new_node->prev != NULL)
    {
        new_node->prev->next = new_node;
    }
    else{
        (*head) = new_node;
    }
    
}

void printList(struct node* head)
{
    struct node* last;
    while (head != NULL)
    {
        printf("%d ", head->data);
        last = head;
        head = head->next;
    }
    printf("\n");
    while (last != NULL)
    {
        printf("%d ", last->data);
        last = last->prev;
    }
}

int main()
{
    struct node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 5);

    pushBefore(&head, head->next, 4);
    printList(head);

    return 0;
}
