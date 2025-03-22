#include <stdio.h>
#include <string.h>
#define MAXSIZE 5 // Maximum stack size

struct stack
{
    char urls[MAXSIZE][50]; // Stack to store website URLs
    int top;
};
typedef struct stack STACK;
STACK s;

void visitWebsite();
void goBack();
void viewHistory();

int main()
{
    int choice;
    int option = 1;
    s.top = -1; // Initialize stack

    printf("BROWSER HISTORY MANAGEMENT\n");

    while (option)
    {
        printf("------------------------------------------\n");
        printf("      1    -->    VISIT A NEW WEBSITE     \n");
        printf("      2    -->    GO BACK (Previous Page) \n");
        printf("      3    -->    VIEW HISTORY            \n");
        printf("      4    -->    EXIT                    \n");
        printf("------------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice)
        {
        case 1:
            visitWebsite();
            break;
        case 2:
            goBack();
            break;
        case 3:
            viewHistory();
            break;
        case 4:
            printf("Exiting Browser History Management.\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }

        printf("Do you want to continue (0 or 1)? ");
        scanf("%d", &option);
        getchar(); // Consume newline character
    }
}

/* Function to visit a new website (Push operation) */
void visitWebsite()
{
    if (s.top == MAXSIZE - 1)
    {
        printf("History is full! Cannot visit more websites.\n");
        return;
    }

    printf("Enter the website URL: ");
    fgets(s.urls[++s.top], 50, stdin);
    s.urls[s.top][strcspn(s.urls[s.top], "\n")] = 0; // Remove newline character

    printf("Visited: %s\n", s.urls[s.top]);
}

/* Function to go back to the previous website (Pop operation) */
void goBack()
{
    if (s.top == -1)
    {
        printf("No previous websites. History is empty!\n");
        return;
    }

    printf("Going back from: %s\n", s.urls[s.top]);
    s.top--; // Remove the top website
    if (s.top != -1)
    {
        printf("Now on: %s\n", s.urls[s.top]);
    }
    else
    {
        printf("No websites left in history.\n");
    }
}

/* Function to display browsing history */
void viewHistory()
{
    if (s.top == -1)
    {
        printf("Browsing history is empty.\n");
        return;
    }

    printf("\nBrowsing History:\n");
    for (int i = s.top; i >= 0; i--)
    {
        printf("%d. %s\n", i + 1, s.urls[i]);
    }
    printf("\n");
}
