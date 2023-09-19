#include <stdio.h>

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int size)
{
    int swap, isSorted = 0;
    for (int i = 0; i < size; i++)
    {
        isSorted = 1;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {65, 2, 1, 23, 0, 3};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);
    bubbleSort(arr, size);
    display(arr, size);
    return 0;
}