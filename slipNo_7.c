#include <stdio.h>
#include <string.h>

void bubbleSort(char *arr)
{

    char swap;
    int isSorted = 0;
    int size = strlen(arr);
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
                isSorted = 0;
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
    char arr[20];
    printf("PLease Enter YOur Name :-");
    gets(arr);
    puts(arr);
    bubbleSort(arr);
    puts(arr);
    return 0;
}