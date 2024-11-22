// Exercise 1
// Write a program in C that will implement a simple data processing function that accepts a 
// callback function as an argument. The data processing function will process an array of integers 
// and call the provided callback function for each element in the array. The callback function will be 
// responsible for doing something with each element. Implement element printing and element square printing 
// callback functions and call data processing function with each of these callbacks.

// #include <stdio.h>

// void process_data(int *arr, int size, void (*callback)(int)) {
//     for (int i = 0; i < size; i++) {
//         callback(arr[i]);
//     }
// }

// void print_element(int element) {
//     printf("Element: %d\n", element);
// }

// void print_square(int element) {
//     printf("Square: %d\n", element * element);
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     printf("Processing with print_element callback:\n");
//     process_data(arr, size, print_element);

//     printf("\nProcessing with print_square callback:\n");
//     process_data(arr, size, print_square);

//     return 0;
// }





// Exercise 2
// Write a program in C that calculates average and sum of integer array elements. Use a function to perform the calculations and don’t use array subscript “[ ]” operator.

// #include <stdio.h>

// void calculate_sum_and_average(int *arr, int size, int *sum, float *average) {
//     *sum = 0;
//     for (int i = 0; i < size; i++) {
//         *sum += *(arr + i);
//     }
//     *average = (float)(*sum) / size;
// }

// int main() {
//     int arr[] = {10, 20, 30, 40, 50};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int sum;
//     float average;

//     calculate_sum_and_average(arr, size, &sum, &average);

//     printf("Sum: %d\n", sum);
//     printf("Average: %.2f\n", average);

//     return 0;
// }





// Exercise 3
// Write a program in C that uses double pointers to manipulate a 2D array. The program should read rows and columns from the user and allocate memory dynamically for a 2D array, then read and display elements using double pointers.

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int rows, cols;

//     printf("Enter number of rows: ");
//     scanf("%d", &rows);
//     printf("Enter number of columns: ");
//     scanf("%d", &cols);

//     int **arr = (int **)malloc(rows * sizeof(int *));
//     for (int i = 0; i < rows; i++) {
//         arr[i] = (int *)malloc(cols * sizeof(int));
//     }

//     printf("Enter the elements of the 2D array:\n");
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("Element at [%d][%d]: ", i, j);
//             scanf("%d", *(arr + i) + j); 
//         }
//     }

//     printf("The elements of the 2D array are:\n");
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("%d ", *(*(arr + i) + j));
//         }
//         printf("\n");
//     }

//     for (int i = 0; i < rows; i++) {
//         free(arr[i]);
//     }
//     free(arr);

//     return 0;
// }





// Homework 1
// Create a C program that demonstrates passing pointers to functions. 
// Write a function that accepts an integer pointer and doubles the value it points to. 
// Display the result in the main function.

// #include <stdio.h>
// void double_value(int *ptr) {
//     *ptr = *ptr * 2;
// }

// int main() {
//     int num;
//     printf("Enter an integer: ");
//     scanf("%d", &num);
//     printf("Before doubling: %d\n", num);
//     double_value(&num);
//     printf("After doubling: %d\n", num);

//     return 0;
// }




// Homework 2
// Write a C program that copies the contents of one integer array into another using pointers. Pass both arrays and their sizes as function arguments.

// #include <stdio.h>

// void copy_array(int *src, int *dest, int size) {
//     for (int i = 0; i < size; i++) {
//         *(dest + i) = *(src + i); 
//     }
// }

// int main() {
//     int size;
//     printf("Enter the number of elements: ");
//     scanf("%d", &size);

//     int src[size], dest[size];
//     printf("Enter the elements for the source array:\n");
//     for (int i = 0; i < size; i++) {
//         printf("Element %d: ", i + 1);
//         scanf("%d", src + i);
//     }
//     copy_array(src, dest, size);
//     printf("The contents of the destination array are:\n");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", *(dest + i));
//     }
//     printf("\n");
//     return 0;
// }





// Homework 3
// Write a program in C that implements an integer stack data structure using pointers. Create functions for push, pop, and display operations which have pointer to the stack as parameter. Use a dynamic array to store stack elements.

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int *arr;    
//     int top;      
//     int capacity;  
// } 
// Stack;
// void init_stack(Stack *stack, int capacity) {
//     stack->arr = (int *)malloc(capacity * sizeof(int));  
//     if (!stack->arr) {
//         printf("Memory allocation failed!\n");
//         exit(1);
//     }
//     stack->top = -1;  
//     stack->capacity = capacity;
// }

// int is_full(Stack *stack) {
//     return stack->top == stack->capacity - 1;
// }

// int is_empty(Stack *stack) {
//     return stack->top == -1;
// }

// void push(Stack *stack, int value) {
//     if (is_full(stack)) {
//         printf("Stack Overflow! Cannot push %d\n", value);
//         return;
//     }
//     stack->arr[++stack->top] = value; 
// }

// int pop(Stack *stack) {
//     if (is_empty(stack)) {
//         printf("Stack Underflow! Stack is empty.\n");
//         return -1; 
//     }
//     return stack->arr[stack->top--];  
// }

// void display(Stack *stack) {
//     if (is_empty(stack)) {
//         printf("Stack is empty.\n");
//         return;
//     }
//     printf("Stack elements: ");
//     for (int i = 0; i <= stack->top; i++) {
//         printf("%d ", stack->arr[i]);
//     }
//     printf("\n");
// }

// int main() {
//     Stack stack;
//     int capacity, choice, value;
//     printf("Enter the capacity of the stack: ");
//     scanf("%d", &capacity);
//     init_stack(&stack, capacity);

//     while (1) {
//         printf("\nStack Operations Menu:\n");
//         printf("1. Push\n");
//         printf("2. Pop\n");
//         printf("3. Display\n");
//         printf("4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter the value to push: ");
//                 scanf("%d", &value);
//                 push(&stack, value);
//                 break;
//             case 2:
//                 value = pop(&stack);
//                 if (value != -1) {
//                     printf("Popped value: %d\n", value);
//                 }
//                 break;
//             case 3:
//                 display(&stack);
//                 break;
//             case 4:
//                 free(stack.arr);
//                 printf("Exiting program.\n");
//                 return 0;
//             default:
//                 printf("Invalid choice! Please try again.\n");
//         }
//     }
//     return 0;
// }
