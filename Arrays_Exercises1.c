// Exercise 1
// Write a program in C to find the maximum difference between any 
// two array elements such that the larger element appears after the smaller number.

// #include <stdio.h>
// #include <limits.h>

// int findMaxDifference(int arr[], int size) {
//     int minElement = INT_MAX; 
//     int maxDifference = INT_MIN; 

//     for (int i = 0; i < size; i++) {
//         if (arr[i] < minElement) {
//             minElement = arr[i];
//         }

//         int currentDifference = arr[i] - minElement;
//         if (currentDifference > maxDifference) {
//             maxDifference = currentDifference;
//         }
//     }

//     return maxDifference;
// }

// int main() {
//     int size;

//     printf("Enter the size of the array: ");
//     scanf("%d", &size);

//     int arr[size];

//     printf("Enter the elements of the array:\n");
//     for (int i = 0; i < size; i++) {
//         scanf("%d", &arr[i]);
//     }

//     int maxDifference = findMaxDifference(arr, size);
//     if (maxDifference > 0) {
//         printf("The maximum difference is: %d\n", maxDifference);
//     } else {
//         printf("No valid difference found (array is non-decreasing).\n");
//     }
//     return 0;
// }



// Exercise 2
// #include <stdio.h>
// int partition(int arr[], int low, int high) {
//     int pivot = arr[high]; 
//     int i = low - 1;     

//     for (int j = low; j < high; j++) {
//         if (arr[j] <= pivot) {
//             i++;
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }

//     int temp = arr[i + 1];
//     arr[i + 1] = arr[high];
//     arr[high] = temp;

//     return i + 1;
// }

// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         int pi = partition(arr, low, high);
//         quickSort(arr, low, pi - 1); 
//         quickSort(arr, pi + 1, high);
//     }
// }

// int main() {
//     int size;
//     printf("Enter the size of the array: ");
//     scanf("%d", &size);

//     int arr[size];
//     printf("Enter the elements of the array:\n");
//     for (int i = 0; i < size; i++) {
//         scanf("%d", &arr[i]);
//     }

//     quickSort(arr, 0, size - 1);

//     printf("Sorted array in ascending order:\n");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }



// Exercise 3
// Write a program in C to read a matrix from user and check whether it is diagonal or not.

// #include <stdio.h>

// int main() {
//     int rows, cols, isDiagonal = 1;
//     printf("Enter the number of rows and columns: ");
//     scanf("%d %d", &rows, &cols);
//     if (rows != cols) {
//         printf("The matrix is NOT a diagonal matrix (it is not square).\n");
//         return 0;
//     }

//     int matrix[10][10];
//     printf("Enter the elements of the matrix:\n");
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             scanf("%d", &matrix[i][j]);
//             if (i != j && matrix[i][j] != 0) {
//                 isDiagonal = 0;
//             }
//         }
//     }

//     if (isDiagonal) {
//         printf("The matrix is a diagonal matrix.\n");
//     } else {
//         printf("The matrix is NOT a diagonal matrix.\n");
//     }

//     return 0;
// }









// Homework 1 
// Given an integer array and a target value, write a program in C to find two numbers 
// in the array that sum up to the target. Print their indices.

// #include <stdio.h>
// void findTwoSum(int arr[], int size, int target) {
//     for (int i = 0; i < size; i++) {
//         for (int j = i + 1; j < size; j++) {
//             if (arr[i] + arr[j] == target) {
//                 printf("Indices: %d and %d\n", i, j);
//                 return;
//             }
//         }
//     }
//     printf("No two numbers found that add up to the target.\n");
// }

// int main() {
//     int arr[] = {2, 7, 11, 15};
//     int target = 9;
//     int size = sizeof(arr) / sizeof(arr[0]);
//     findTwoSum(arr, size, target);
//     return 0;
// }







// Homework 2
// Write a program in C that reads a series of integers into an array and then displays 
// a histogram of the data, showing the frequency of each number. Use ‘*’ to display the histogram.
// #include <stdio.h>

// void printHistogram(int arr[], int size) {
//     int freq[100] = {0};
//     int maxNum = 0;

//     for (int i = 0; i < size; i++) {
//         freq[arr[i]]++;
//         if (arr[i] > maxNum) {
//             maxNum = arr[i];
//         }
//     }

//     printf("\nHistogram:\n");
//     for (int i = 0; i <= maxNum; i++) {
//         if (freq[i] > 0) {
//             printf("%d: ", i);
//             for (int j = 0; j < freq[i]; j++) {
//                 printf("*");
//             }
//             printf("\n");
//         }
//     }
// }

// int main() {
//     int arr[100];
//     int size;

//     printf("Enter the number of elements: ");
//     scanf("%d", &size);

//     printf("Enter the elements (non-negative integers): ");
//     for (int i = 0; i < size; i++) {
//         scanf("%d", &arr[i]);
//         if (arr[i] < 0) {
//             printf("Please enter only non-negative integers.\n");
//             i--;
//         }
//     }

//     printHistogram(arr, size);
//     return 0;
// }




// Homework 3
// Write a C program that merges two sorted integer arrays into a single sorted array.
// #include <stdio.h>

// void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
//     int i = 0, j = 0, k = 0;

//     while (i < size1 && j < size2) {
//         if (arr1[i] < arr2[j]) {
//             result[k++] = arr1[i++];
//         } else {
//             result[k++] = arr2[j++];
//         }
//     }

//     while (i < size1) {
//         result[k++] = arr1[i++];
//     }

//     while (j < size2) {
//         result[k++] = arr2[j++];
//     }
// }

// int main() {
//     int arr1[] = {1, 3, 5, 7};
//     int arr2[] = {2, 4, 6, 8};
//     int size1 = sizeof(arr1) / sizeof(arr1[0]);
//     int size2 = sizeof(arr2) / sizeof(arr2[0]);
//     int result[size1 + size2];

//     mergeSortedArrays(arr1, size1, arr2, size2, result);

//     printf("Merged Sorted Array: ");
//     for (int i = 0; i < size1 + size2; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");

//     return 0;
// }