#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    int n = 10; 
    if (argc == 2) {
        n = atoi(argv[1] + 1); 
    }

    char lines[MAX_LINES][MAX_LENGTH];
    int count = 0;

    printf("Enter lines of text (Ctrl+D to stop):\n");

    while (fgets(lines[count], MAX_LENGTH, stdin) != NULL) {
        count++;
    }

    int start = count > n ? count - n : 0;

    printf("\nLast %d lines:\n", n);
    for (int i = start; i < count; i++) {
        printf("%s", lines[i]);
    }

    return 0;
}
