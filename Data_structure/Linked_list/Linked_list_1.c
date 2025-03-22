// A simple C program to implement a linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a node
struct Node
{
    char data[10];     // First data field (string)
    int address;       // Second data field (integer)
    struct Node *next; // Pointer to next node
};

// Function to create a new node
struct Node *createNode(char *name, int addr)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, name);
    newNode->address = addr;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("[%s | %d] -> ", temp->data, temp->address);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // Creating nodes
    struct Node *A = createNode("A", 400);
    struct Node *X = createNode("X", 100);
    struct Node *Y = createNode("Y", 200);
    struct Node *C = createNode("C", 402);
    struct Node *Z = createNode("Z", 300);
    struct Node *B = createNode("B", 401);
    struct Node *P = createNode("P", 403);

    // Linking nodes as per the final linked list
    A->next = X;
    X->next = Y;
    Y->next = C;
    C->next = Z;
    Z->next = B;
    B->next = P;
    P->next = NULL; // End of the list

    // Print final linked list
    printf("Final Linked List:\n");
    printList(A);

    return 0;
}
