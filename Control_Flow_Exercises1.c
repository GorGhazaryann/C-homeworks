// Exercise 1
// Write a C program that reads integer value from user, converts it to string and prints. Use a separate function to perform the conversion (void to_str(int n, char s[])).
// Enhance the conversion function to take an additional “base” argument. The function should perform conversion taking into account the base.

// #include <stdio.h>
// #include <string.h>
// void to_str(int n, char s[], int base) {
//     int i = 0;
//     int isNegative = 0;
//     if (n < 0 && base == 10) {
//         isNegative = 1;
//         n = -n;
//     }

//     if (n == 0) {
//         s[i++] = '0';
//     }

//     while (n > 0) {
//         int digit = n % base;
//         if (digit < 10) {
//             s[i++] = digit + '0'; 
//         } else {
//             s[i++] = digit - 10 + 'A';
//         }
//         n = n / base;
//     }


//     if (isNegative) {
//         s[i++] = '-';
//     }

//     s[i] = '\0';

//     for (int j = 0, k = i - 1; j < k; j++, k--) {
//         char temp = s[j];
//         s[j] = s[k];
//         s[k] = temp;
//     }
// }

// int main() {
//     int n, base;
//     char str[100];
//     printf("Enter an integer: ");
//     scanf("%d", &n);
//     printf("Enter the base (2 for binary, 10 for decimal, 16 for hexadecimal): ");
//     scanf("%d", &base);
//     to_str(n, str, base);
//     printf("The number in base %d is: %s\n", base, str);
//     return 0;
// }




// Exercise 2
// Write a C program that reads a string from user and prints all sub-strings which are separated by a white space.
// Enhance the program to find and print the longest sub-string.

// #include <stdio.h>
// #include <string.h>

// #define MAX_LENGTH 100
// void find_substrings(char str[]) {
//     char *token = strtok(str, " ");

//     // Print each substring
//     printf("Substrings: \n");
//     while (token != NULL) {
//         printf("%s\n", token);
//         token = strtok(NULL, " "); 
//     }
// }

// void find_longest_substring(char str[]) {
//     char *token = strtok(str, " ");
//     char longest[MAX_LENGTH] = "";
    
//     while (token != NULL) {
//         if (strlen(token) > strlen(longest)) {
//             strcpy(longest, token);
//         }
//         token = strtok(NULL, " "); 
//     }

//     printf("\nLongest Substring: %s\n", longest);
// }

// int main() {
//     char str[MAX_LENGTH];

//     printf("Enter a string: ");
//     fgets(str, MAX_LENGTH, stdin); 
//     str[strcspn(str, "\n")] = 0;  

//     find_substrings(str);

//     find_longest_substring(str);

//     return 0;
// }






// Exercise 3
// Write a C program that plays a simple "Guess the Number" game with the user. The program should generate a random number between 1 and 100 (inclusive) and ask the user to guess that number. The program should provide feedback to the user after each guess, indicating whether the guess was too high, too low, or correct. The user should continue guessing until they guess the correct number.
// Note: The program should use the rand() function to generate a random number. You should include #include <stdlib.h> for this.
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int main() {
//     int number, guess, attempts = 0;
//     srand(time(0));
//     number = rand() % 100 + 1;
//     printf("Guess the Number Game!\n");
//     do {
//         printf("Enter your guess (between 1 and 100): ");
//         scanf("%d", &guess);
//         attempts++;

//         if (guess > number) {
//             printf("Too high! Try again.\n");
//         } else if (guess < number) {
//             printf("Too low! Try again.\n");
//         } else {
//             printf("Correct! You guessed the number in %d attempts.\n", attempts);
//         }
//     } while (guess != number);

//     return 0;
// }