/**
 * @file main.c
 * @brief Program to sort an array of integers entered by the user.
 * 
 * This program dynamically allocates memory for an array of integers,
 * sorts the array using a separate function, and demonstrates dynamic
 * memory management in C.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Sorts an array of integers in ascending order.
 * 
 * @param arr Pointer to the array of integers.
 * @param n Number of elements in the array.
 */
void sort_array(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort_array(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
