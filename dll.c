#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;
struct node *create_ll(struct node *start);
struct node *insert_l(struct node *start);
struct node *delete_node(struct node *start);
void display(struct node *start);

void main() {
    int choice;
    printf("\n1. Create Linked List\n2. Insert Node\n3. Delete Node\n4. Display Linked List\n5. Exit\n");
    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:
                start = create_ll(start);
                break;
            case 2:
                start = insert_l(start);
                break;
            case 3:
                start = delete_node(start);
                break;
            case 4:
                display(start);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=5);
}

struct node *create_ll(struct node *start) {
    struct node *newnode, *ptr;
    int num;
    printf("Enter -1 to stop entering nodes.\n");
    printf("Enter the data for the new node: ");
    scanf("%d",&num);
    while(num!= -1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;
        if(start == NULL) {
            newnode->prev = NULL;
            start = newnode;
        }
        else {
            ptr = start;
            while(ptr->next!= NULL)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->prev = ptr;
        }
        printf("Enter the data for the new node: ");
        scanf("%d",&num);
    }
    return start;
}

struct node *insert_l(struct node *start) {
    struct node *newnode, *ptr;
    int n1,n2;
    printf("Enter the data before which new node is to be inserted: ");
    scanf("%d",&n1);
    printf("Enter the data for the new node: ");
    scanf("%d",&n2);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n2;
    if(start->data == n1) {
        newnode->next = start;
        start->prev = newnode;
        newnode->prev = NULL;
        start = newnode;
    }
    else {
        ptr = start;
        while(ptr->next!= NULL && ptr->next->data!= n1)
            ptr = ptr->next;
        if(ptr->next!= NULL) {
            newnode->next = ptr->next;
            ptr->next->prev = newnode;
            newnode->prev = ptr;
            ptr->next = newnode;
        }
        else
            printf("Node with given data not found in the list.\n");
    }
    return start;
}

struct node *delete_node(struct node *start) {
    struct node *ptr;
    int num;
    printf("Enter the data of the node to be deleted: ");
    scanf("%d",&num);
    ptr=start;
    while(ptr->data!= num){
        ptr=ptr->next;
    }
    if(ptr==start) {
        start=ptr->next;
        ptr->next->prev = NULL;
        free(ptr);
        return start;
    }
    if(ptr->next==NULL) {
        ptr->prev->next = NULL;
        free(ptr);
        return start;
    }
    if(ptr==NULL){
        printf("Node with given data not found in the list.\n");
        return start;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return start;
}

void display(struct node *start) {
    struct node *ptr;
    if(start==NULL){
        printf("List is empty.\n");
        return;
    }
    printf("List is: ");
    ptr=start;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
