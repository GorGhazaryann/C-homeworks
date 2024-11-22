// Exercise 1
// Create a C program to print each line of it’s input that contains a particular ‘pattern’ or string of characters. The program should allow the user to input a ‘pattern’ string and a text. The program should print the number of matches at the end.

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char pattern[100], line[200];
//     int match_count = 0;

//     printf("Enter the pattern string: ");
//     fgets(pattern, sizeof(pattern), stdin);
//     pattern[strcspn(pattern, "\n")] = '\0';

//     printf("Enter lines of text (Ctrl+D or Ctrl+Z to end input):\n");

//     while (fgets(line, sizeof(line), stdin) != NULL) {
//         line[strcspn(line, "\n")] = '\0';

//         if (strstr(line, pattern) != NULL) {
//             printf("Match found: %s\n", line);
//             match_count++;
//         }
//     }

//     printf("Number of matches: %d\n", match_count);

//     return 0;
// }


// Exercise 2
// Create a C program that checks whether user provided number can be expresses as a 
// sum of two Prime numbers, if yes then show all possible combinations.

// #include <stdio.h>
// #include <stdbool.h>

// bool is_prime(int num) {
//     if (num <= 1) return false;
//     for (int i = 2; i * i <= num; i++) {
//         if (num % i == 0) return false;
//     }
//     return true;
// }

// int main() {
//     int num;
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     printf("Possible combinations of two prime numbers that sum to %d:\n", num);
//     bool found = false;
//     for (int i = 2; i <= num / 2; i++) {
//         if (is_prime(i) && is_prime(num - i)) {
//             printf("%d + %d = %d\n", i, num - i, num);
//             found = true;
//         }
//     }

//     if (!found) {
//         printf("No such combinations found.\n");
//     }
//     return 0;
// }




// Exercise 3
// Create a C calculator program that provides the operators ‘+’, ‘-’, ‘*’, ‘/’, ‘%’ and reads the 
// expressions in the postfix (reverse Polish) notation. After calculating the expression result it should 
// print result and allow another expression to be entered by the user. The program should exit when EOF is read.

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #define MAX_SIZE 100

// int apply_operator(int a, int b, char operator) {
//     switch (operator) {
//         case '+': return a + b;
//         case '-': return a - b;
//         case '*': return a * b;
//         case '/': return a / b;
//         case '%': return a % b;
//         default: return 0;
//     }
// }

// int evaluate_postfix(char *expression) {
//     int stack[MAX_SIZE];
//     int top = -1;

//     for (int i = 0; expression[i] != '\0'; i++) {
//         char ch = expression[i];

//         if (isdigit(ch)) {
//             stack[++top] = ch - '0';
//         } else if (ch == ' ' || ch == '\t') {
//             continue;
//         } else {
//             int b = stack[top--];
//             int a = stack[top--];
//             stack[++top] = apply_operator(a, b, ch);
//         }
//     }
    
//     return stack[top];
// }

// int main() {
//     char expression[MAX_SIZE];

//     printf("Enter postfix expressions (Ctrl+D or Ctrl+Z to exit):\n");
//     while (fgets(expression, sizeof(expression), stdin)) {
//         expression[strcspn(expression, "\n")] = '\0';
//         int result = evaluate_postfix(expression);
//         printf("Result: %d\n", result);
//         printf("Enter another expression or EOF to exit:\n");
//     }

//     printf("Exiting program...\n");
//     return 0;
// }


// Homework 1
// Create a C calculator program that provides the operators ‘+’, ‘-’, ‘*’, ‘/’, ‘%’ and 
// reads the expressions in the infix notation. After calculating the expression result 
// it should print result and allow another expression to be entered by the user. The program 
// should exit when EOF is read.

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <math.h>
// #include <string.h>

// #define MAX 100

// typedef struct {
//     int data[MAX];
//     int top;
// } Stack;

// void initStack(Stack *s);
// int isEmpty(Stack *s);
// int isFull(Stack *s);
// void push(Stack *s, int value);
// int pop(Stack *s);
// int peek(Stack *s);
// int precedence(char op);
// int isOperator(char ch);
// int evaluatePostfix(char *postfix);
// void infixToPostfix(char *infix, char *postfix);

// int main() {
//     char infix[MAX], postfix[MAX];
    
//     while (printf("Enter expression: "), fgets(infix, MAX, stdin) != NULL) {
//         infix[strcspn(infix, "\n")] = 0;

//         infixToPostfix(infix, postfix);
//         int result = evaluatePostfix(postfix);

//         printf("Result: %d\n", result);
//     }

//     return 0;
// }

// void initStack(Stack *s) {
//     s->top = -1;
// }

// int isEmpty(Stack *s) {
//     return s->top == -1;
// }

// int isFull(Stack *s) {
//     return s->top == MAX - 1;
// }

// void push(Stack *s, int value) {
//     if (!isFull(s)) {
//         s->data[++(s->top)] = value;
//     }
// }

// int pop(Stack *s) {
//     if (!isEmpty(s)) {
//         return s->data[(s->top)--];
//     }
//     return -1; 
// }

// int peek(Stack *s) {
//     if (!isEmpty(s)) {
//         return s->data[s->top];
//     }
//     return -1; 
// }

// int precedence(char op) {
//     switch (op) {
//         case '+':
//         case '-':
//             return 1;
//         case '*':
//         case '/':
//         case '%':
//             return 2;
//         default:
//             return 0;
//     }
// }

// int isOperator(char ch) {
//     return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
// }


// void infixToPostfix(char *infix, char *postfix) {
//     Stack s;
//     initStack(&s);
//     int i = 0, j = 0;
//     char ch;
    
//     while ((ch = infix[i++]) != '\0') {
//         if (isdigit(ch)) {
//             postfix[j++] = ch;
//         } else if (ch == '(') {
//             push(&s, ch);
//         } else if (ch == ')') {
//             while (!isEmpty(&s) && peek(&s) != '(') {
//                 postfix[j++] = pop(&s);
//             }
//             pop(&s);
//         } else if (isOperator(ch)) {
//             while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
//                 postfix[j++] = pop(&s);
//             }
//             push(&s, ch);
//         }
//     }

//     while (!isEmpty(&s)) {
//         postfix[j++] = pop(&s);
//     }

//     postfix[j] = '\0';
// }


// int evaluatePostfix(char *postfix) {
//     Stack s;
//     initStack(&s);
//     int i = 0;
//     char ch;

//     while ((ch = postfix[i++]) != '\0') {
//         if (isdigit(ch)) {
//             push(&s, ch - '0');
//         } else if (isOperator(ch)) {
//             int val2 = pop(&s);
//             int val1 = pop(&s);
//             switch (ch) {
//                 case '+': push(&s, val1 + val2); break;
//                 case '-': push(&s, val1 - val2); break;
//                 case '*': push(&s, val1 * val2); break;
//                 case '/': push(&s, val1 / val2); break;
//                 case '%': push(&s, val1 % val2); break;
//             }
//         }
//     }

//     return pop(&s);
// }



// Homework 2
// Write a C program that allows two players to play a text-based game of Tic-Tac-Toe using a 1D array to represent the board. The program should display a Tic-Tac-Toe board and allow players to take turns entering their moves until one player wins or the game ends in a draw. Use functions to implement the game logic.
// Here are the steps to follow:
// Create a 1D array of size 9 to represent the Tic-Tac-Toe board. Initialize it with empty spaces (' ') to represent unoccupied cells.
// Display the empty board to the players at the beginning of the game.
// Allow two players to take turns entering their moves (e.g., "Player X, enter a position:").
// Check for valid moves (e.g., within the board boundaries and not already occupied).
// Update the board array with the players' moves.
// Check for a winning condition (e.g., three in a row horizontally, vertically, or diagonally).
// Check for a draw condition (all cells are occupied without a winner).
// Display the updated board after each move.
// Announce the winner or declare a draw when the game ends.

// #include <stdio.h>

// void display_board(char board[]) {
//     printf("\n");
//     for (int i = 0; i < 9; i++) {
//         printf(" %c ", board[i]);
//         if (i % 3 == 2) printf("\n");
//         else printf("|");
//     }
//     printf("\n");
// }

// int check_winner(char board[], char player) {
//     for (int i = 0; i < 3; i++) {
//         if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) return 1;
//         if (board[i] == player && board[i + 3] == player && board[i + 6] == player) return 1;
//     }
//     if (board[0] == player && board[4] == player && board[8] == player) return 1;
//     if (board[2] == player && board[4] == player && board[6] == player) return 1;
    
//     return 0;
// }

// int check_draw(char board[]) {
//     for (int i = 0; i < 9; i++) {
//         if (board[i] == ' ') return 0;
//     }
//     return 1;
// }

// int main() {
//     char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//     int move, player_turn = 1;
//     char player_symbol;
    
//     printf("Welcome to Tic-Tac-Toe!\n");
    
//     while (1) {
//         display_board(board);
        
//         if (player_turn) player_symbol = 'X';
//         else player_symbol = 'O';
        
//         printf("Player %c, enter a position (1-9): ", player_symbol);
//         scanf("%d", &move);
//         move--;
        
//         if (move < 0 || move > 8 || board[move] != ' ') {
//             printf("Invalid move. Try again.\n");
//             continue;
//         }
        
//         board[move] = player_symbol;
        
//         if (check_winner(board, player_symbol)) {
//             display_board(board);
//             printf("Player %c wins!\n", player_symbol);
//             break;
//         }

//         if (check_draw(board)) {
//             display_board(board);
//             printf("It's a draw!\n");
//             break;
//         }
        
//         player_turn = !player_turn;
//     }
//     return 0;
// }
