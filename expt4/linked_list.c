#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int regNo;
    char name[50];
    struct Student *next;
};

struct Student *head = NULL;

void addStudent()
{
    struct Student *newNode;
    struct Student *temp;

    newNode = (struct Student *)malloc(sizeof(struct Student));

    printf("Enter registration number: ");
    scanf("%d", &newNode->regNo);

    printf("Enter student name: ");
    scanf(" %[^\n]", newNode->name);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Student added successfully.\n");
}

void removeStudent()
{
    int regNo;
    struct Student *temp;
    struct Student *previous;

    printf("Enter registration number to remove: ");
    scanf("%d", &regNo);

    temp = head;
    previous = NULL;

    while (temp != NULL && temp->regNo != regNo)
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Student not found.\n");
        return;
    }

    if (previous == NULL)
        head = temp->next;
    else
        previous->next = temp->next;

    free(temp);

    printf("Student removed successfully.\n");
}

void displayList()
{
    struct Student *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nRegistration Number\tName\n");

    while (temp != NULL)
    {
        printf("%d\t\t\t%s\n", temp->regNo, temp->name);
        temp = temp->next;
    }
}

void countStudents()
{
    int count = 0;
    struct Student *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total participants: %d\n", count);
}

void sortList()
{
    struct Student *current;
    struct Student *nextNode;

    int tempRegNo;
    char tempName[50];

    for (current = head; current != NULL; current = current->next)
    {
        for (nextNode = current->next;
             nextNode != NULL;
             nextNode = nextNode->next)
        {
            if (current->regNo > nextNode->regNo)
            {
                tempRegNo = current->regNo;
                current->regNo = nextNode->regNo;
                nextNode->regNo = tempRegNo;

                strcpy(tempName, current->name);
                strcpy(current->name, nextNode->name);
                strcpy(nextNode->name, tempName);
            }
        }
    }

    printf("List sorted by registration number.\n");
}

void reverseList()
{
    struct Student *previous = NULL;
    struct Student *current = head;
    struct Student *nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;

    printf("List reversed successfully.\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Workshop Enrollment ---\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display List\n");
        printf("4. Count Participants\n");
        printf("5. Sort List\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            removeStudent();
            break;

        case 3:
            displayList();
            break;

        case 4:
            countStudents();
            break;

        case 5:
            sortList();
            break;

        case 6:
            reverseList();
            break;

        case 7:
            printf("Program ended.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 7);

    return 0;
}