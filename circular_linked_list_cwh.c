#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void circular_ll(struct node* head){
    struct node *ptr = head;
    printf("Element is: %d\n", ptr->data);
    ptr = ptr->next;

    while (ptr != head)
    {
        printf("Element is: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("----------\n");
    
}

void circular_ll2(struct node* head){
    struct node* ptr = head;

    do
    {
        printf("Element is: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("---------\n");
    
}

struct node* insert_at_first(struct node *head, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data  = data;
    struct node* p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node of this cll
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
};

struct node * delete_at_index(struct node * head, int index)
{
    struct node * p = head;
    struct node * q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;    
    free(q);
    return head;
};
struct node * delete_at_value(struct node * head, int value)
{
    struct node * p = head;
    struct node * q = head->next;
    while (q->data != value && q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;    
    }
    free(q);
    return head;
};



int main(){
    
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;

    // Dynamically requesting the memories in heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = head;

    // circular_ll(head);
    head = insert_at_first(third, 69);
    printf("Circular Linked list before deletion:\n");
    circular_ll2(head);

    // delete_at_index(head, 3);
    // delete_at_value(head, 2);
    // printf("Circular Linked list after deletion:\n");
    // circular_ll2(head);

    return 0;
}