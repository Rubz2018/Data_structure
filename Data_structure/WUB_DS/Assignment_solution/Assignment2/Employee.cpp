#include <stdio.h>
#include <string.h>

struct Employee
{
    char name[50];
    int id;
    char department[50];
};

int main()
{
    struct Employee employees[] = {{"Alice", 101, "HR"}, {"Bob", 102, "IT"}, {"Charlie", 103, "Finance"}};
    int size = sizeof(employees) / sizeof(employees[0]);
    char searchName[50];

    printf("Enter the employee name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(employees[i].name, searchName) == 0)
        {
            printf("Employee Found:\n");
            printf("Name: %s\n", employees[i].name);
            printf("ID: %d\n", employees[i].id);
            printf("Department: %s\n", employees[i].department);
            return 0;
        }
    }

    printf("Employee not found.\n");
    return 1;
}