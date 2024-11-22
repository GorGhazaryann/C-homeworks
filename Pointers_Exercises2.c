// Exercise 1
// Write a C program that reads a matrix size from user, allocates memory to hold a matrix of integers with the provided size, reads matrix elements, calculates and prints the sum of matrix columns elements. Don’t use array subscript operators for solving the exercise.

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int rows, cols;

//     printf("Enter the number of rows: ");
//     scanf("%d", &rows);
//     printf("Enter the number of columns: ");
//     scanf("%d", &cols);

//     int **matrix = (int **)malloc(rows * sizeof(int *));
//     for (int i = 0; i < rows; i++) {
//         matrix[i] = (int *)malloc(cols * sizeof(int));
//     }

//     printf("Enter the elements of the matrix:\n");
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("Element [%d][%d]: ", i + 1, j + 1);
//             scanf("%d", (*(matrix + i) + j));
//         }
//     }

//     printf("\nSum of elements in each column:\n");
//     for (int j = 0; j < cols; j++) {
//         int sum = 0;
//         for (int i = 0; i < rows; i++) {
//             sum += *(*(matrix + i) + j);
//         }
//         printf("Column %d sum: %d\n", j + 1, sum);
//     }

//     for (int i = 0; i < rows; i++) {
//         free(matrix[i]);
//     }
//     free(matrix);

//     return 0;
// }


// Exercise 2
// Write a C program that performs and demonstrates all allowed operations on a pointers.

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int a = 10;
//     int *ptr = &a;

//     printf("Value of 'a' using pointer: %d\n", *ptr);

//     printf("Address of 'a' before increment: %p\n", (void*)ptr);
//     ptr++;
//     printf("Address of 'a' after increment: %p\n", (void*)ptr);

//     int **ptr_to_ptr = &ptr;
//     printf("Value of 'a' through pointer to pointer: %d\n", **ptr_to_ptr);

//     int arr[] = {1, 2, 3, 4, 5};
//     int *arr_ptr[5];
//     for (int i = 0; i < 5; i++) {
//         arr_ptr[i] = &arr[i];
//         printf("Value at arr[%d] using array of pointers: %d\n", i, *arr_ptr[i]);
//     }

//     int *dynamic_arr = (int*)malloc(5 * sizeof(int));
//     if (dynamic_arr == NULL) {
//         printf("Memory allocation failed\n");
//         return 1;
//     }

//     for (int i = 0; i < 5; i++) {
//         dynamic_arr[i] = i + 1;
//         printf("Value at dynamic_arr[%d]: %d\n", i, dynamic_arr[i]);
//     }

//     int *arr_start = arr;
//     printf("First element in array using pointer arithmetic: %d\n", *(arr_start));

//     free(dynamic_arr);

//     return 0;
// }




// Exercise 3
// Write a simple menu driven calculator program in C that uses callbacks to perform the calculations.

// #include <stdio.h>

// typedef int (*operation)(int, int);

// int add(int a, int b) {
//     return a + b;
// }

// int subtract(int a, int b) {
//     return a - b;
// }

// int multiply(int a, int b) {
//     return a * b;
// }

// int divide(int a, int b) {
//     if (b != 0)
//         return a / b;
//     else {
//         printf("Error! Division by zero.\n");
//         return 0;
//     }
// }

// int main() {
//     int choice, a, b;
//     operation op = NULL;

//     printf("Simple Calculator\n");

//     while (1) {
//         printf("\nMenu:\n");
//         printf("1. Add\n");
//         printf("2. Subtract\n");
//         printf("3. Multiply\n");
//         printf("4. Divide\n");
//         printf("5. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         if (choice == 5) {
//             printf("Exiting...\n");
//             break;
//         }

//         printf("Enter two numbers: ");
//         scanf("%d %d", &a, &b);

//         switch (choice) {
//             case 1: op = add; break;
//             case 2: op = subtract; break;
//             case 3: op = multiply; break;
//             case 4: op = divide; break;
//             default: printf("Invalid choice! Please try again.\n"); continue;
//         }

//         printf("Result: %d\n", op(a, b));
//     }

//     return 0;
// }




// Homework 1
// Write a program in C that has a memory leak and using “Valgrind” tool find the memory leak.

// Note: Valgrind is a Linux based tool, so if your PC is Windows, then you need to install either Cygwin or WSL, which will allow you to run Linux programs on Windows. After installing these programs you have to install GCC and Valgrind.

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int *ptr = (int *)malloc(sizeof(int) * 10); 

//     if (ptr == NULL) {
//         printf("Memory allocation failed!\n");
//         return 1;
//     }

//     for (int i = 0; i < 10; i++) {
//         ptr[i] = i + 1;
//     }

//     for (int i = 0; i < 10; i++) {
//         printf("%d ", ptr[i]);
//     }
//     printf("\n");

//     return 0;
// }




// Homework 2
// Write a C program that generates all permutations of a given string. For example, if the input is "ABC" the program should output all possible permutations: "ABC", "ACB," "BAC," "BCA", "CAB" and "CBA".

// #include <stdio.h>
// #include <string.h>

// void swap(char *x, char *y) {
//     char temp = *x;
//     *x = *y;
//     *y = temp;
// }

// void permute(char *str, int l, int r) {
//     if (l == r) {
//         printf("%s\n", str); 
//     } else {
//         for (int i = l; i <= r; i++) {
//             swap((str + l), (str + i)); 
//             permute(str, l + 1, r);      
//             swap((str + l), (str + i)); 
//         }
//     }
// }

// int main() {
//     char str[] = "ABC"; 
//     int n = strlen(str); 

//     printf("All permutations of the string are:\n");
//     permute(str, 0, n - 1);  

//     return 0;
// }





// Homework 3
// Write a C program to reverse a string using a recursive function. Avoid using loops and array subscript operators for the reversal.


// #include <stdio.h>

// void reverseString(char *str, char *start, char *end) {
//     if (start >= end) {
//         return;
//     }

//     char temp = *start;
//     *start = *end;
//     *end = temp;
    
//     reverseString(str, start + 1, end - 1);
// }

// int main() {
//     char str[] = "Hello, World!";
    
//     char *start = str;
//     char *end = str;
//     while (*end != '\0') {
//         end++;
//     }
//     end--; 
    
//     reverseString(str, start, end);
//     printf("Reversed string: %s\n", str);
//     return 0;
// }