// Number pyramid
#include <stdio.h>

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printStars(int count) {
    for (int i = 0; i < count; i++) {
        printf("*");
    }
}

void generatePyramid(int rows) {
    for (int i = 1; i <= rows; i++) {
        printSpaces(rows - i);
        printStars(i);
        printf("\n");
    }
}

int main() {
    int rows;
    
    printf("Input number of rows: ");
    scanf("%d", &rows);

    generatePyramid(rows);

    return 0;
}
