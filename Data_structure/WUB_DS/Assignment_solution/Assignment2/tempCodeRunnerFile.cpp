#include <stdio.h>

struct Order
{
    int orderId;
    char customerName[50];
    float amount;
};

int binarySearch(struct Order orders[], int size, int searchOrderId)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (orders[mid].orderId == searchOrderId)
        {
            return mid;
        }
        else if (orders[mid].orderId < searchOrderId)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    struct Order orders[] = {{1001, "Alice", 100.0}, {1002, "Bob", 200.5}, {1003, "Charlie", 150.2}};
    int size = sizeof(orders) / sizeof(orders[0]);

    int searchOrderId;
    printf("Enter the order ID to search: ");
    scanf("%d", &searchOrderId);

    int index = binarySearch(orders, size, searchOrderId);
    if (index != -1)
    {
        printf("Order Found:\n");
        printf("Order ID: %d\n", orders[index].orderId);
        printf("Customer Name: %s\n", orders[index].customerName);
        printf("Amount: %.2f\n", orders[index].amount);
    }
    else
    {
        printf("Order not found.\n");
    }

    return 0;
}