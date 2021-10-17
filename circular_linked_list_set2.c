#include<stdio.h>
#include<stdlib.h>

// structure for a node
struct node
{
    int data;
    struct node *next;
};

// fuction to insert a node at the beginning of a circular linked list
void push(struct node **head, int data)
{
    struct node *ptr1 = (struct node*)malloc(sizeof(struct node));
    struct node *temp = *head;
    ptr1->data = data;
    ptr1->next = *head;

    if (*head != NULL)
    {
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = ptr1;
    }
    else
    {
        ptr1->next = ptr1;
    }
    *head = ptr1;
}


void printList(struct node *head)
{
    struct node *last = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", last->data);
            last = last->next;
        } while (last != head);
        
    }
    
}


int main()
{
    struct node *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    // printList(head->next);
    printList(head);
    // printf("\n%d", head->data);

    return 0;
}
