#include <stdio.h>

struct Item
{
    int id;
    char name[50];
    int stock;
};

int main()
{
    struct Item items[] = {{101, "Apple", 50}, {102, "Banana", 30}, {103, "Orange", 20}};
    int size = sizeof(items) / sizeof(items[0]);
    int searchId;

    printf("Enter the item ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < size; i++)
    {
        if (items[i].id == searchId)
        {
            printf("Item Found:\n");
            printf("ID: %d\n", items[i].id);
            printf("Name: %s\n", items[i].name);
            printf("Stock: %d\n", items[i].stock);
            return 0;
        }
    }

    printf("Item not found.\n");
    return 1;
}