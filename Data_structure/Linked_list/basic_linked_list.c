#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Allocate memory for three nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Assign data and link nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // Print the linked list details
    printf("Start = %p\n", (void *)head);
    printf("Data in Start = %d\n", head->data);
    printf("Pointer in first Node = %p\n", (void *)head->next);

    printf("Second = %p\n", (void *)second);
    printf("Data in Second Node = %d\n", second->data);
    printf("Pointer in Second Node = %p\n", (void *)second->next);

    printf("Third = %p\n", (void *)third);
    printf("Data in Third Node = %d\n", third->data);
    printf("Pointer in Third Node = %p\n", (void *)third->next);

    // Print the linked list structure in one line
    printf("[%p]   [%d][%p]   [%d][%p]   [%d][%p]\n",
           (void *)head, head->data, (void *)head->next,
           second->data, (void *)second->next,
           third->data, (void *)third->next);

    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
