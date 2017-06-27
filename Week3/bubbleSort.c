#include <stdio.h>

#define SIZE 100

void bubbleSort(int *arr);
void selectionSort(int *arr);
void insertionSort(int *arr);
void merge(int *arr, int index1, int index2, int index3, int index4);
void mergeSort(int init, int end, int *arr);

void printArr(int *arr);

int main(int argc, char const *argv[]) {
        // Initialize array
        int arr[SIZE];
        for (int i = SIZE - 1; i >= 0; i = i - 1)
                arr[SIZE - 1 - i] = i + 1;

        printf("Before: \n");
        printArr(arr);
        //bubbleSort(arr);
        //selectionSort(arr);
        //insertionSort(arr);
        mergeSort(0, SIZE - 1, arr);
        printf("After: \n");
        printArr(arr);
        return 0;
}

void bubbleSort(int *arr)
{
        int temp;
        int swaps = 0;
        int bound = SIZE - 1;
        for (int j = 0; j < SIZE - 1; j = j + 1)
        {
                for (int i = 0; i < bound; i = i + 1)
                {
                        if (arr[i] > arr[i + 1])
                        {
                                swaps = swaps + 1;
                                temp = arr[i];
                                arr[i] = arr[i + 1];
                                arr[i + 1] = temp;
                        }
                }
                bound =  bound - 1;
                if (swaps == 0)
                        break;
                swaps = 0;
        }
}

void selectionSort(int *arr)
{
        int smallest;
        int indxSmall;
        for (int i = 0; i < SIZE; i = i + 1)
        {
                smallest = arr[i];
                indxSmall = i;
                for (int j = i; j < SIZE; j = j + 1)
                {
                        if (arr[j] < smallest)
                        {
                                smallest = arr[j];
                                indxSmall = j;
                        }
                }
                arr[indxSmall] = arr[i];
                arr[i] = smallest;
        }
}

void insertionSort(int *arr)
{
        int temp;
        int j;
        int insert = 1;
        for (int i = 1; i < SIZE; i = i + 1)
        {
                temp = arr[i];
                j = i;
                while (insert)
                {
                        if (temp < arr[j - 1])
                        {
                                arr[j] = arr[j - 1];
                                if (j == 1)
                                {
                                        arr[0] = temp;
                                        break;
                                }
                        }
                        else
                        {
                                arr[j] = temp;
                                break;
                        }
                        j = j - 1;
                }
        }
}

void merge(int *arr, int index1, int index2, int index3, int index4)
{
        int i1 = index1, i2 = index2, j1 = index3, j2 = index4;
        int total = i2 - i1 + j2 - j1 + 2;
        int temp[SIZE];
        int i = 0;
        while (i1 <= i2 && j1 <= j2)
        {
                if (arr[i1] < arr[j1])
                {
                        temp[i] = arr[i1];
                        i1++;
                }
                else
                {
                        temp[i] = arr[j1];
                        j1++;
                }
                i++;
        }

        if (i1 > i2)
        {
                for (int j = j1; j1 <= j2; j++)
                {
                        temp[i] = arr[j];
                        i++;
                }
        }
        else
        {
                for (int j = i1; j <= i2; j++)
                {
                        temp[i] = arr[j];
                        i++;
                }
        }

        // Move temp to original
        for (int j = 0; j < total; j++)
        {
                arr[index1++] = temp[j];
        }
}

void mergeSort(int i, int j, int *arr)
{
        int mid = (i + j) / 2;
        if (i == j)
                arr[i] = arr[i];
        else
        {
                mergeSort(i, mid, arr);
                mergeSort(mid + 1, j, arr);
                merge(arr, i, mid, mid + 1, j);
        }
}

void printArr(int *arr)
{
        for (int i = 0; i < SIZE; i = i + 1)
                printf("%d ", arr[i]);
        printf("\n");
}
