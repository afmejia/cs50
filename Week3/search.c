#include <stdio.h>

#define SIZE 100

void fillArray(int *arr);
void linearSearch(int number, int *arr);
void printArray(int *arr);

int main(int argc, char const *argv[]) {
        // Create and fill array
        int arr[SIZE];
        fillArray(arr);

        // Prompt the user to Enter a number
        int number;
        printf("Please enter a number: ");
        scanf("%d", &number);

        // Search the number
        linearSearch(number, arr);
        return 0;
}

void fillArray(int *arr)
{
        for (int i = 0; i < SIZE; i++)
                arr[i] = i + 1;
}

void linearSearch(int number, int *arr)
{
  for (int i = 0; i < SIZE; i++)
  {
    if (number == arr[i])
    {
      printf("Number %d found at position: %d\n", number, i);
      break;
    }
    else
      if (i == SIZE - 1)
        printf("The number %d is not\n", );
  }
}

void printArray(int *arr)
{
        for (int i = 0; i < SIZE; i++)
                printf("%d\t", arr[i]);
        printf("\n");
}
