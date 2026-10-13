#include <stdio.h>
#include <stdlib.h>

// Define Node structure for Circular Linked List
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** tail, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*tail == NULL) {
        *tail = newNode;
        newNode->next = *tail; // Points to itself forming a circle
    } else {
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
        *tail = newNode; // Tail updates to the new node
    }
    printf("Inserted %d into the circular linked list.\n", value);
}

// Function to insert a node at the beginning
void insertBegin(struct Node** tail, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*tail == NULL) {
        *tail = newNode;
        newNode->next = *tail;
    } else {
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
    }
    printf("Inserted %d at the beginning.\n", value);
}

// Function to delete a node from the beginning
void deleteBegin(struct Node** tail) {
    if (*tail == NULL) {
        printf("List is empty! Underflow.\n");
        return;
    }

    struct Node* head = (*tail)->next;
    if (*tail == head) { // Only one node in the list
        free(head);
        *tail = NULL;
    } else {
        (*tail)->next = head->next;
        free(head);
    }
    printf("Deleted node from the beginning.\n");
}

// Function to display the circular linked list
void display(struct Node* tail) {
    if (tail == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node* temp = tail->next; // Starts from head
    printf("Circular Linked List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

int main() {
    struct Node* tail = NULL;

    insertEnd(&tail, 10);
    insertEnd(&tail, 20);
    insertEnd(&tail, 30);
    insertBegin(&tail, 5);
    display(tail);

    deleteBegin(&tail);
    display(tail);

    return 0;
}
