#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node
struct Node
{
    char data1[20];    // First data field (e.g., a name or identifier)
    int data2;         // Second data field (e.g., an ID or a number)
    struct Node *next; // Pointer to the next node
};

// Function to create a new node
struct Node *createNode(char *name, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocating memory
    strcpy(newNode->data1, name);                                      // Copy name into the data1 field
    newNode->data2 = value;                                            // Assign value to data2 field
    newNode->next = NULL;                                              // Initialize next pointer to NULL
    return newNode;
}

// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *temp = head; // Temporary pointer to traverse the list
    while (temp != NULL)
    {
        printf("Data1: %s, Data2: %d\n", temp->data1, temp->data2);
        temp = temp->next;
    }
}

// Main function to test the structure
int main()
{
    struct Node *head = createNode("A", 400);
    head->next = createNode("X", 100);
    head->next->next = createNode("Y", 200);

    printList(head);

    return 0;
}
