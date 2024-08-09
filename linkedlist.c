#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node *next;
};

struct node *createnode(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void InsertionAtBeginning(int value, struct node **head) {
    struct node *newnode = createnode(value);
    newnode->next = *head;
    *head = newnode;
}

void InsertionAtEnd(int value, struct node *head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct node *newnode = createnode(value);
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void PrintList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
	
    struct node *head = NULL;

    InsertionAtBeginning(20, &head);
    printf("Linked list after inserting the node 20 at the beginning:\n");
    PrintList(head);

    InsertionAtEnd(10, head);
    printf("Linked list after inserting the node 10 at the end:\n");
    PrintList(head);

    return 0;
}
