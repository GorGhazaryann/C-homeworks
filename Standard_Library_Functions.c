#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
    // Exercise 1
    char str1[101], str2[101], copy[101];

    printf("Enter the first string (max 100 characters): ");
    fgets(str1, 101, stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter the second string (max 100 characters): ");
    fgets(str2, 101, stdin);
    str2[strcspn(str2, "\n")] = 0;

    char concatenated[202];
    strcpy(concatenated, str1);
    strcat(concatenated, str2);
    printf("Concatenated string: %s\n", concatenated);

    if (strcmp(str1, str2) == 0) {
        printf("The strings are the same.\n");
    } else {
        printf("The strings are different.\n");
    }

    printf("Length of first string: %lu\n", strlen(str1));
    printf("Length of second string: %lu\n", strlen(str2));

    strcpy(copy, str1);
    printf("Copy of the first string: %s\n", copy);

    // Exercise 2
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Current date: %04d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    printf("Current time: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Exercise 3
    double num;
    printf("Enter a floating-point number: ");
    scanf("%lf", &num);

    printf("Square root: %.2f\n", sqrt(num));
    printf("Rounded to nearest integer: %.0f\n", round(num));
    printf("Sine value (in radians): %.2f\n", sin(num));

    return 0;
}
