#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

void sortStrings(char arr[][MAX_LENGTH], int n, int (*cmp)(const char *, const char *)) {
    char temp[MAX_LENGTH];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int ascending(const char *a, const char *b) {
    return strcmp(a, b);
}

int descending(const char *a, const char *b) {
    return strcmp(b, a);
}

int main() {
    char strings[MAX_STRINGS][MAX_LENGTH];
    int n, choice;

    printf("Enter number of strings: ");
    scanf("%d", &n);
    
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    printf("Choose sorting order (1 for Ascending, 2 for Descending): ");
    scanf("%d", &choice);

    if (choice == 1) {
        sortStrings(strings, n, ascending);
    } else {
        sortStrings(strings, n, descending);
    }

    printf("Sorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
