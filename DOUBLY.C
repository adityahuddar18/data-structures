#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create_node() {
    struct node *temp; int data1;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&data1);
    temp->data=data1;
    temp->next=NULL;
    temp->prev=NULL;
    
    
    
}

void insert_beg(struct node **head) {
    struct node *ptr,*temp;
    ptr=create_node();
    if(*head==NULL) {
        *head=ptr;
    }
    else {
    
    temp=*head;
    ptr->next=*head;
    ptr->prev=NULL;
    temp->prev=ptr;
    *head=ptr;
    
    }
}

void display(struct node *head) {
    struct node *ptr;
    ptr=head;
    if(ptr==NULL) {
        printf("\nEmpty Linked List");
    }
    else {
        printf("\nDATA IN LINKED List: ");
        while(ptr!=NULL) {
            printf(" %d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

void delete_specific(struct node **head,int pos) {
    struct node *ptr, *temp;
    if(*head==NULL) {
        printf("List is Empty\n");
    }
    else if((*head)->next==NULL) {
        free(*head);
        *head=NULL;
    }
    else {
        ptr=*head;
        temp=*head;
        int n=pos;
        while(n!=1) {
            ptr=ptr->next;
            n--;
        }
        (ptr->prev)->next=ptr->next;
        (ptr->next)->prev=ptr->prev;
        free(ptr);
    }
}


void main() {
    struct node *head=NULL;
    // struct node *head2=NULL;
    while(1) {
        printf("\n1.Insert Begining  2.Display contain 3.Delete random place\n");
        int c;
        scanf("%d",&c);
        
        if(c==1) {
            insert_beg(&head);
        }
        else if(c==2) {
            display(head);
        }
        else if(c==3) {
            printf("where do u want to delete a node?: ");
            int pos1;
            scanf("%d",&pos1);
            delete_specific(&head,pos1);
        }
        else {
            break;
        }
        
    }
    
}





























