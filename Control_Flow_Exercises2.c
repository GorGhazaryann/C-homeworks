// Exercise 1

// Create a C program for a simple calculator that can perform basic arithmetic operations: addition, subtraction, multiplication, and division. The program should display a menu to the user, allowing them to choose the operation they want to perform and then input two numbers to perform the chosen operation. After performing the operation, the program should display the result.
// Here are the requirements for the program:
// Display a menu with the following options:
// 1. Addition, 2. Subtraction, 3. Multiplication, 4. Division, 5. Quit (to exit the program)
// Allow the user to choose an option by entering a corresponding number (e.g., 1 for addition, 2 for subtraction, etc.).
// If the user selects an operation (1-4), prompt them to enter two numbers (operands) on which to perform the chosen operation.
// Perform the selected operation and display the result.
// After displaying the result, return to the menu to allow the user to perform another operation or quit the program.

// #include <stdio.h>

// int main() {
//     int choice;
//     float num1, num2, result;

//     do {
//         printf("Simple Calculator\n");
//         printf("1. Addition\n");
//         printf("2. Subtraction\n");
//         printf("3. Multiplication\n");
//         printf("4. Division\n");
//         printf("5. Quit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         if (choice >= 1 && choice <= 4) {
//             printf("Enter two numbers: ");
//             scanf("%f %f", &num1, &num2);
//         }

//         switch (choice) {
//             case 1:
//                 result = num1 + num2;
//                 printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
//                 break;
//             case 2:
//                 result = num1 - num2;
//                 printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
//                 break;
//             case 3:
//                 result = num1 * num2;
//                 printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
//                 break;
//             case 4:
//                 if (num2 != 0) {
//                     result = num1 / num2;
//                     printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
//                 } else {
//                     printf("Error! Division by zero.\n");
//                 }
//                 break;
//             case 5:
//                 printf("Exiting program.\n");
//                 break;
//             default:
//                 printf("Invalid choice! Please choose a valid option.\n");
//         }

//     } while (choice != 5);

//     return 0;
// }





// Exercise 2

// Create a C program that calculates a student's final grade based on the following criteria: homework, quizzes, and exams. The program should ask the user for their scores in each category and then calculate and display their final grade.
// Here are the requirements for the program:
// Ask the user to input the following scores, each on a scale of 0 to 100:
// 1. Homework (weighted 20%), 2. Quiz (weighted 30%), 3. Exam (weighted 50%)
// Calculate the weighted average of the scores to determine the final grade. Use the following formula: FinalGrade = (Homework * 0.2) + (Quiz * 0.3) + (Exam * 0.5)
// Display the final grade to the user.
// Provide a letter grade based on the following scale:
// A: 90-100, B: 80-89, C: 70-79, D: 60-69, F: Below 60
// Display the letter grade to the user based on the calculated final grade.
// Implement error checking to ensure that the user enters valid scores (between 0 and 100) and provide appropriate feedback if the input is invalid.
// Allow the user to repeat the process for calculating grades for multiple students or quit the program as they choose.

// #include <stdio.h>
// char get_letter_grade(float final_grade) {
//     if (final_grade >= 90) {
//         return 'A';
//     } else if (final_grade >= 80) {
//         return 'B';
//     } else if (final_grade >= 70) {
//         return 'C';
//     } else if (final_grade >= 60) {
//         return 'D';
//     } else {
//         return 'F';
//     }
// }

// int main() {
//     float homework, quiz, exam, final_grade;
//     char letter_grade;
//     int continue_program = 1;

//     while (continue_program) {
//         printf("Enter Homework score (0-100): ");
//         scanf("%f", &homework);
//         if (homework < 0 || homework > 100) {
//             printf("Invalid input! Homework score must be between 0 and 100.\n");
//             continue;
//         }

//         printf("Enter Quiz score (0-100): ");
//         scanf("%f", &quiz);
//         if (quiz < 0 || quiz > 100) {
//             printf("Invalid input! Quiz score must be between 0 and 100.\n");
//             continue;
//         }

//         printf("Enter Exam score (0-100): ");
//         scanf("%f", &exam);
//         if (exam < 0 || exam > 100) {
//             printf("Invalid input! Exam score must be between 0 and 100.\n");
//             continue;
//         }

//         final_grade = (homework * 0.2) + (quiz * 0.3) + (exam * 0.5);

//         letter_grade = get_letter_grade(final_grade);

//         printf("Final Grade: %.2f\n", final_grade);
//         printf("Letter Grade: %c\n", letter_grade);

//         printf("\nWould you like to calculate another grade? (1 for yes, 0 for no): ");
//         scanf("%d", &continue_program);
//     }

//     printf("Goodbye!\n");
//     return 0;
// }
