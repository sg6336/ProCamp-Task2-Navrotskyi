// Task2_1:
// Write a function that finds the biggest element in an array of ints.

#include "ProCamp_Task2_1_biggest.h"

void task2_1_main_biggest()
{
    printf("Task2_1: finds the biggest element in an array of ints \n");
    printf("Start \n\n");

	int arr[] = { 10, 324, 45, 90, 9808, 19, 4500 };
	int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nBiggest element: %d", biggest(arr, n));

    printf("\n\n");
    printf("Task2_1: finds the biggest element in an array of ints \n");
    printf("Stop \n\n");
}

int biggest(int arr[], int n)
{
    int i;

    int max = arr[0];

    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}