// Exercise 3-3
#include <stdio.h>

void expand(char s1[], char s2[]) {
    char symbol;
    int i, j = 0;

    while ((symbol = s1[i]) != '\0') { 
        if (s1[++i] == '-' && s1[i+1] >= symbol){
            i++;
            while (symbol < s1[i]){
                s2[j++] = symbol++;
            }
        }else{
            s2[j++] = symbol;
        }
    }
    s2[j] = '\0';
}
    

int main() {
    char s1[] = "Hello 0-9";
    char s2[1000];
    expand(s1, s2);
    printf("Expanded: %s", s2);    
    return 0;
}