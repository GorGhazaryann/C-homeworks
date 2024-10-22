// Task 1
// #include <stdio.h>
// #include <string.h>

// int main() {
//     int n;
//     printf("Enter the number of names: ");
//     scanf("%d", &n);
    
//     char names[n][100];
//     char duplicates[n][100];
//     int dupCount = 0;

//     // Input names
//     for (int i = 0; i < n; i++) {
//         printf("Enter name %d: ", i + 1);
//         scanf("%s", names[i]);
//     }

//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (strcmp(names[i], names[j]) == 0) {
//                 int alreadyFound = 0;
//                 for (int k = 0; k < dupCount; k++) {
//                     if (strcmp(duplicates[k], names[i]) == 0) {
//                         alreadyFound = 1;
//                         break;
//                     }
//                 }
//                 if (!alreadyFound) {
//                     strcpy(duplicates[dupCount], names[i]);
//                     dupCount++;
//                 }
//             }
//         }
//     }

//     if (dupCount > 0) {
//         printf("Duplicate names:\n");
//         for (int i = 0; i < dupCount; i++) {
//             printf("%s\n", duplicates[i]);
//         }
//     } else {
//         printf("No duplicates found.\n");
//     }

//     return 0;
// }






// Task 2
// #include <stdio.h>

// int main() {
//     int rows, cols;

//     printf("Enter number of rows and columns: ");
//     scanf("%d %d", &rows, &cols);

//     int matrix[rows][cols];
//     int transpose[cols][rows];

//     printf("Enter the matrix elements:\n");
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             scanf("%d", &matrix[i][j]);
//         }
//     }

//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             transpose[j][i] = matrix[i][j];
//         }
//     }

//     printf("Transpose of the matrix:\n");
//     for (int i = 0; i < cols; i++) {
//         for (int j = 0; j < rows; j++) {
//             printf("%d ", transpose[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }



// Task 3
// #include <stdio.h>
// #include <string.h>

// #define MAX_LINES 100
// #define MAX_LINE_LENGTH 100

// int main(int argc, char *argv[]) {
//     int n = 10;  
//     char lines[MAX_LINES][MAX_LINE_LENGTH];
//     int lineCount = 0;


//     if (argc == 2 && argv[1][0] == '-') {
//         n = atoi(argv[1] + 1); 
//     }

//     printf("Enter text (Ctrl+D to end input):\n");
//     while (fgets(lines[lineCount], MAX_LINE_LENGTH, stdin) != NULL && lineCount < MAX_LINES) {
//         lineCount++;
//     }

//     printf("Last %d lines:\n", n);
//     int start = (lineCount > n) ? lineCount - n : 0;
//     for (int i = start; i < lineCount; i++) {
//         printf("%s", lines[i]);
//     }

//     return 0;
// }



// Task 4
// #include <stdio.h>
// #include <string.h>

// typedef int (*CompareFunc)(const char *, const char *);

// void sortStrings(char arr[][100], int n, CompareFunc cmp) {
//     char temp[100];

//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (cmp(arr[i], arr[j]) > 0) {
//                 // Swap arr[i] and arr[j]
//                 strcpy(temp, arr[i]);
//                 strcpy(arr[i], arr[j]);
//                 strcpy(arr[j], temp);
//             }
//         }
//     }
// }


// int lexicographical(const char *a, const char *b) {
//     return strcmp(a, b);
// }


// int reverseLexicographical(const char *a, const char *b) {
//     return strcmp(b, a);
// }

// int main() {
//     int n;
//     printf("Enter the number of strings: ");
//     scanf("%d", &n);

//     char strings[n][100];

//     for (int i = 0; i < n; i++) {
//         printf("Enter string %d: ", i + 1);
//         scanf("%s", strings[i]);
//     }

//     int choice;
//     printf("Choose sorting order: 1 for lexicographical, 2 for reverse lexicographical: ");
//     scanf("%d", &choice);

//     if (choice == 1) {
//         sortStrings(strings, n, lexicographical);
//     } else if (choice == 2) {
//         sortStrings(strings, n, reverseLexicographical);
//     } else {
//         printf("Invalid choice!\n");
//         return 1;
//     }

//     printf("Sorted strings:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%s\n", strings[i]);
//     }

//     return 0;
// }
