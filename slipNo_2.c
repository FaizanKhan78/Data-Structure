#include <stdio.h>

void input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("PLease Enter Element %d :- ", i);
        scanf("%d", &arr[i]);
    }
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int n, int element)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] > element)
        {
            low = -mid;
        }
        else
        {
            low = +mid;
        }
    }
    return 0;
}

int main()
{
    int n;
    int element, searchIndex;
    printf("Please Enter The Size of Array :- ");
    scanf("%d", &n);
    int arr[n];
    input(arr, n);
    printf("Please Enter Element You Want TO search :- ");
    scanf("%d", &element);
    searchIndex = binarySearch(arr, n, element);
    printf("Element %d Was Found At Index No. %d", element, searchIndex);
    return 0;
}