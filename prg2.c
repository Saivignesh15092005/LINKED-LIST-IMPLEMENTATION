#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the list
struct Node* insertAtBeginning(struct Node *head, int newData) {
    struct Node newNode = (struct Node) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = newData;
    newNode->next = head; // New node points to the old head
    return newNode;      // New node becomes the new head
}

// Function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL; // Initialize an empty list

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    printf("Linked list: ");
    printList(head);

    // --- Add code for other operations like deletion, insertion at end, etc. ---

    // Free allocated memory (important to prevent memory leaks)
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

