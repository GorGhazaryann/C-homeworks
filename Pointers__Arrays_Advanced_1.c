#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 50

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);
    
    printf("Enter the names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    printf("Duplicate names:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                printf("%s\n", names[i]);
                break;
            }
        }
    }

    return 0;
}
