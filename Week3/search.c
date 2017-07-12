#include <stdio.h>

#define SIZE 1000

void fillArray(int *arr);
void linearSearch(int number, int *arr);
void binarySearch(int number, int *arr);
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
        //linearSearch(number, arr);
        binarySearch(number, arr);
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
        printf("The number %d is not in the list\n", number);
  }
}

void binarySearch(int number, int *arr)
{
  int start = 0;
  int end = SIZE - 1;
  int found = 0;
  int mid;
  while(start <= end && found == 0 && start != end)
  {
    mid = (start + end) / 2;
    if (arr[mid] == number)
      found = 1;
    else if (arr[mid] < number)
      start = mid + 1;
    else
      end = mid - 1;
  }
  if (found == 1)
    printf("Number %d found in position %d\n", number, mid);
  else if (end == start && number == arr[start])
    printf("Number %d found in position %d\n", number, start);
  else
    printf("Number %d not found in the sequence\n", number);
}

void printArray(int *arr)
{
        for (int i = 0; i < SIZE; i++)
                printf("%d\t", arr[i]);
        printf("\n");
}
