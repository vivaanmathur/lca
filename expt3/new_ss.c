#include <stdio.h>

void linearSearch(int n, int a[n])
{
    int key;
    printf("enter key: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("element found at %d.\n", i);
            return;
        }
    }
    printf("Element not found.\n");
}
void binarySearch(int n, int a[n])
{
    int key;
    printf("enter key: ");
    scanf("%d", &key);

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (key > a[mid])
        {
            low = mid + 1;
        }
        else if (key == a[mid])
        {
            printf("element found. %d\n", mid);
            return;
        }
        else if (key < a[mid])
        {
            high = mid - 1;
        }
    }

    printf("element not found.\n");
}
void insertionSort(int n, int a[n])
{
    if (n == 1)
    {
        return;
    }

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void selectionSort(int n, int a[n])
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
void shellSort(int n, int a[n])
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i++)
        {
            int key = a[i];
            int j = i - gap;

            while (j >= 0 && key < a[j])
            {
                a[j + gap] = a[j];
                j -= gap;
            }

            a[j + gap] = key;
        }
    }
}
void display(int n, int a[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter no. of elements: ");

    scanf("%d", &n);

    int a[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int run = 1;
    while (run)
    {
        int choice;
        printf("Menu:1.Linear\t2.Binary\t3.Insertion\t4.Selection\t5.Shell\t6.Display\t7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            linearSearch(n, a);
            break;
        case 2:
            binarySearch(n, a);
            break;
        case 3:
            insertionSort(n, a);
            break;
        case 4:
            selectionSort(n, a);
            break;
        case 5:
            shellSort(n, a);
            break;
        case 6:
            display(n, a);
            break;
        case 7:
            run = 0;
            break;
        default:
            break;
        }
    }
}