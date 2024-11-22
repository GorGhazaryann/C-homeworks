// Exercise 1
// Write a C program to sort an array of integers in ascending order using 
// the bubble sort algorithm. Use a function for sorting.

// #include <stdio.h>
// void bubbleSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);

//     int arr[n];
//     printf("Enter the elements of the array:\n");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     bubbleSort(arr, n);

//     printf("Sorted array in ascending order: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }



// Exercise 2
// Implement a C program to generate the first N numbers in the 
// Fibonacci series without using recursion. Use a loop to calculate and display the series.

// #include <stdio.h>
// int main() {
//     int n, first = 0, second = 1, next;
//     printf("Enter the number of terms in the Fibonacci series: ");
//     scanf("%d", &n);
//     if (n <= 0) {
//         printf("Please enter a positive integer.\n");
//     } else {
//         printf("Fibonacci Series: ");
        
//         for (int i = 1; i <= n; i++) {
//             if (i == 1) {
//                 printf("%d ", first);
//                 continue;
//             }
//             if (i == 2) {
//                 printf("%d ", second);
//                 continue;
//             }
//             next = first + second;
//             first = second;
//             second = next;
//             printf("%d ", next);
//         }
//         printf("\n");
//     }
//     return 0;
// }



// Exercise 3
// Write a C program that performs a binary search on a sorted array 
// to find a specific element. The program should print the index of the found element 
// or “not found”. Use a function to implement the search logic.

// #include <stdio.h>
// int binarySearch(int arr[], int n, int target) {
//     int left = 0, right = n - 1;

//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (arr[mid] == target) {
//             return mid; 
//         }
//         if (arr[mid] < target) {
//             left = mid + 1;
//         }
//         else {
//             right = mid - 1;
//         }
//     }
//     return -1;
// }

// int main() {
//     int n, target;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);

//     int arr[n];

//     printf("Enter the elements of the sorted array:\n");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     printf("Enter the element to search for: ");
//     scanf("%d", &target);

//     int result = binarySearch(arr, n, target);

//     if (result != -1) {
//         printf("Element found at index %d.\n", result);
//     } else {
//         printf("Element not found.\n");
//     }
//     return 0;
// }




// Homework 1
// Create a C program that concatenates two strings entered by the user. Use a function to perform the concatenation.
// #include <stdio.h>
// #include <string.h>

// void concatenateStrings(char str1[], char str2[], char result[]) {
//     int i = 0, j = 0;

//     while (str1[i] != '\0') {
//         result[i] = str1[i];
//         i++;
//     }

//     while (str2[j] != '\0') {
//         result[i] = str2[j];
//         i++;
//         j++;
//     }

//     result[i] = '\0';
// }

// int main() {
//     char str1[100], str2[100], result[200];

//     printf("Enter the first string: ");
//     fgets(str1, sizeof(str1), stdin);
//     str1[strcspn(str1, "\n")] = '\0'; 

//     printf("Enter the second string: ");
//     fgets(str2, sizeof(str2), stdin);
//     str2[strcspn(str2, "\n")] = '\0'; 

//     concatenateStrings(str1, str2, result);

//     printf("Concatenated String: %s\n", result);

//     return 0;
// }





// Homework 2
// Write a C program that calculates the greatest common divisor (GCD) and 
// least common multiple (LCM) of two integers. Use functions to perform the calculations.
// #include <stdio.h>
// int calculateGCD(int a, int b) {
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

// int calculateLCM(int a, int b) {
//     return (a * b) / calculateGCD(a, b);
// }

// int main() {
//     int num1, num2, gcd, lcm;
//     printf("Enter two integers: ");
//     scanf("%d %d", &num1, &num2);

//     gcd = calculateGCD(num1, num2);
//     lcm = calculateLCM(num1, num2);

//     printf("GCD of %d and %d: %d\n", num1, num2, gcd);
//     printf("LCM of %d and %d: %d\n", num1, num2, lcm);
//     return 0;
// }





// Homework 3
// Implement a C program that checks if a given number is a perfect number
// (equal to the sum of its proper divisors). Use a function to perform the check.
#include <stdio.h>
int isPerfectNumber(int num) {
    int sum = 0;

    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum == num;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPerfectNumber(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }
    return 0;
}