#include<stdio.h>
#include<stdlib.h>

struct list {
    int data;
    struct list* next;
};

void traverse(struct list* head){
    printf("Sir here! is your Linked list.\n");
    struct list* ptr = head;
    int i=1;
    if(ptr==NULL){
        printf("List is Empty.");
    }
    while(ptr != NULL){
        printf("value %d is = %d\n",i,ptr->data);
        ptr = ptr->next;
        i++;
    }
}

struct list *insertAtEnd(struct list *head, int data){
    struct list *ptr = (struct list*) malloc(sizeof(struct list));
    ptr->data = data;
    ptr->next = NULL;
    struct list *end = head;
    while(end->next != NULL){
        end = end->next;
    }
    end->next = ptr;
    return head;
};

struct list* deleteAtBeg(struct list* head){
    if(head == NULL){
        printf("List is Empty.\n");
        return NULL;
    }
    printf("Deleted %d\n",head->data);
    struct list* ptr = head->next;
    free(head);
    return ptr;
};

int main(){
    struct list* head,*second,*third,*forth;

    // // Allocate memory in dynamic memory (heap)
    // head = (struct list *) malloc(sizeof(struct  list));
    // second = (struct list *) malloc(sizeof(struct  list));
    // third = (struct list *) malloc(sizeof(struct  list));
    // forth = (struct list *) malloc(sizeof(struct  list));

    // // linking nodes.
    // head->data = 14;
    // head->next = second;
    // second->data = 28;
    // second->next = third;
    // third->data = 32;
    // third->next = forth;
    // forth->data = 42;
    // forth->next = NULL;

    // traverse(head);

    // // head = insertAtBeg(head,55);
    // // traverse(head);
    // head = insertAtEnd(head,95);
    // traverse(head);
    head = deleteAtBeg(head);
    traverse(head);

    return 0;
}