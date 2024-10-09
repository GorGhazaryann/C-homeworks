// Sum of Prime numbers 
#include <stdio.h>
#include <stdbool.h>


bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


void findPrimeSumCombinations(int num) {
    bool found = false;
    for (int i = 2; i <= num / 2; i++) {
        if (isPrime(i) && isPrime(num - i)) {
            printf("%d + %d = %d\n", i, num - i, num);
            found = true;
        }
    }
    if (!found) {
        printf("The number %d cannot be expressed as the sum of two prime numbers.\n", num);
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    findPrimeSumCombinations(number);

    return 0;
}



