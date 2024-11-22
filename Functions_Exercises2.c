// Exercise 1
// Create a C program that zeroes specified B number of last bits of the A number. 
// The program should read two integer numbers A and B, where -2^31 <= A <= 2^31 – 1 and 
// 0 <= B <= 32. Write zeroing part in the separate function.

// #include <stdio.h>

// int zero_last_bits(int A, int B) {
//     if (B == 0) {
//         return A;
//     }
//     return A & (~((1 << B) - 1));
// }

// int main() {
//     int A, B;
//     printf("Enter A and B: ");
//     scanf("%d %d", &A, &B);

//     if (B < 0 || B > 32) {
//         printf("Invalid value of B. It should be between 0 and 32.\n");
//         return 1;
//     }

//     A = zero_last_bits(A, B);
//     printf("Result: %d\n", A);
//     return 0;
// }




// Exercise 2
// Create a C program that calculates N-th Fibonacci number for a given N user number.

// #include <stdio.h>
// long long fibonacci(int N) {
//     long long a = 0, b = 1, temp;
    
//     if (N == 0) return a;
//     if (N == 1) return b;
    
//     for (int i = 2; i <= N; i++) {
//         temp = a + b;
//         a = b;
//         b = temp;
//     }
//     return b;
// }

// int main() {
//     int N;
//     printf("Enter a number N: ");
//     scanf("%d", &N);
    
//     if (N < 0) {
//         printf("Invalid input! N should be a non-negative integer.\n");
//         return 1;
//     }

//     printf("The %d-th Fibonacci number is: %lld\n", N, fibonacci(N));
//     return 0;
// }


// Exercise 3
// Write a C program that generates and prints a pyramid pattern of ‘*’ characters based on user input number of rows. The program should take an integer as input (n) from the user and then generate a pyramid pattern of n rows. Use functions to implement the pattern generation. For example:
// Input number of rows: 3
//   *
//  * *
// * * *

// #include <stdio.h>

// void printSpaces(int count) {
//     for (int i = 0; i < count; i++) {
//         printf(" ");
//     }
// }

// void printStars(int count) {
//     for (int i = 0; i < count; i++) {
//         printf("*");
//     }
// }

// void generatePyramid(int rows) {
//     for (int i = 1; i <= rows; i++) {
//         printSpaces(rows - i);
//         printStars(i);
//         printf("\n");
//     }
// }

// int main() {
//     int rows;
    
//     printf("Input number of rows: ");
//     scanf("%d", &rows);

//     generatePyramid(rows);

//     return 0;
// }




// Homework 1
// Write a C program that reverses words in a sentence entered by the user. The program 
// should preserve the order of words in the sentence but reverse the characters within each 
// word. Use functions to implement the word reversal logic.

// #include <stdio.h>
// #include <string.h>

// void reverse_word(char word[]) {
//     int start = 0;
//     int end = strlen(word) - 1;
    
//     while (start < end) {
//         char temp = word[start];
//         word[start] = word[end];
//         word[end] = temp;
//         start++;
//         end--;
//     }
// }

// int main() {
//     char sentence[1000];
//     printf("Enter a sentence: ");
//     fgets(sentence, sizeof(sentence), stdin);
    
//     sentence[strcspn(sentence, "\n")] = '\0';
    
//     char word[100];
//     int i = 0, j = 0;
    
//     while (i <= strlen(sentence)) {
//         if (sentence[i] == ' ' || sentence[i] == '\0') {
//             word[j] = '\0'; 
//             reverse_word(word);
//             printf("%s", word);
            
//             if (sentence[i] == ' ') {
//                 printf(" ");
//             }
//             j = 0;
//         } else {
//             word[j] = sentence[i];
//             j++;
//         }
//         i++;
//     }
    
//     printf("\n");
//     return 0;
// }




// Homework 2
// Write a C program that checks if a given string is a palindrome. A palindrome is a word, phrase, number, 
// or other sequence of characters that reads the same forward and backward, ignoring spaces, punctuation, 
// and capitalization. Use functions to implement the palindrome checking logic.

// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>

// int is_palindrome(char str[]) {
//     int start = 0, end = strlen(str) - 1;
    
//     while (start < end) {
//         if (!isalnum(str[start])) {
//             start++;
//         } else if (!isalnum(str[end])) {
//             end--;
//         } else {
//             if (tolower(str[start]) != tolower(str[end])) {
//                 return 0;  
//             }
//             start++;
//             end--;
//         }
//     }
    
//     return 1;
// }

// int main() {
//     char str[1000];
//     printf("Enter a string: ");
//     fgets(str, sizeof(str), stdin);
    
//     str[strcspn(str, "\n")] = '\0';
    
//     if (is_palindrome(str)) {
//         printf("The string is a palindrome.\n");
//     } else {
//         printf("The string is not a palindrome.\n");
//     }
    
//     return 0;
// }