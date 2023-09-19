#include <stdio.h>

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int size)
{
    int indexOfMin, swap;
    for (int i = 0; i < size; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[indexOfMin] > arr[j])
            {
                indexOfMin = j;
            }
        }
        swap = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = swap;
    }
}

int main()
{
    int arr[] = {65, 2, 1, 23, 0, 3};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);
    selectionSort(arr, size);
    display(arr, size);
    return 0;
}