#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *ptr;
};

typedef struct node NODE;

int main()
{
    NODE *head, *first, *temp = NULL, *last, *any;
    int count = 0;
    int choice = 1;
    first = NULL;

    // Creating the linked list
    while (choice)
    {
        head = (NODE *)malloc(sizeof(NODE));
        if (!head)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Memory allocated at = %p\n", (void *)head);
        printf("Enter a data element to insert into the Linked List: ");
        scanf("%d", &head->num);
        head->ptr = NULL;

        if (first != NULL)
        {
            temp->ptr = head;
            temp = head;
        }
        else
        {
            first = temp = head;
        }

        printf("Do you want to continue (Type 0 to exit or any integer to continue)? ");
        scanf("%d", &choice);
    }

    last = head;
    temp->ptr = NULL;

    // Display the linked list
    printf("\nStatus of the linked list:\n");
    temp = first;
    count = 0;
    while (temp != NULL)
    {
        printf("[%p]   [%d] -> ", (void *)temp, temp->num);
        count++;
        temp = temp->ptr;
    }
    printf("[NULL]\n");
    printf("No. of nodes in the list = %d\n", count);

    // Insert a new node at the beginning
    head = (NODE *)malloc(sizeof(NODE));
    if (!head)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Memory allocated at = %p\n", (void *)head);
    printf("Enter a data element to insert at the beginning: ");
    scanf("%d", &head->num);
    head->ptr = first;
    first = head;

    // Display the updated list
    printf("\nUpdated linked list after inserting at the beginning:\n");
    temp = first;
    count = 0;
    while (temp != NULL)
    {
        printf("[%p]   [%d] -> ", (void *)temp, temp->num);
        count++;
        temp = temp->ptr;
    }
    printf("[NULL]\n");

    // Insert a new node at the end
    head = (NODE *)malloc(sizeof(NODE));
    if (!head)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Memory allocated at = %p\n", (void *)head);
    printf("Enter a data element to insert at the end: ");
    scanf("%d", &head->num);
    head->ptr = NULL;
    last->ptr = head;
    last = head;

    // Display the updated list
    printf("\nUpdated linked list after inserting at the end:\n");
    temp = first;
    count = 0;
    while (temp != NULL)
    {
        printf("[%p]   [%d] -> ", (void *)temp, temp->num);
        count++;
        temp = temp->ptr;
    }
    printf("[NULL]\n");

    // Insert a new node in the middle
    int searchv;
    printf("\nEnter a value to search for inserting a new node after it: ");
    scanf("%d", &searchv);

    temp = first;
    while (temp != NULL && temp->num != searchv)
    {
        temp = temp->ptr;
    }

    if (temp == NULL)
    {
        printf("Value not found in the list.\n");
    }
    else
    {
        head = (NODE *)malloc(sizeof(NODE));
        if (!head)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Memory allocated at = %p\n", (void *)head);
        printf("Enter a data element to insert after %d: ", searchv);
        scanf("%d", &head->num);
        head->ptr = temp->ptr;
        temp->ptr = head;
    }

    // Display the updated list
    printf("\nUpdated linked list after inserting in the middle:\n");
    temp = first;
    count = 0;
    while (temp != NULL)
    {
        printf("[%p]   [%d] -> ", (void *)temp, temp->num);
        count++;
        temp = temp->ptr;
    }
    printf("[NULL]\n");

    // Free allocated memory
    temp = first;
    while (temp != NULL)
    {
        NODE *next = temp->ptr;
        free(temp);
        temp = next;
    }

    return 0;
}
