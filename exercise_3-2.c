// Exercise 3-2
#include <stdio.h>

void escape(char s[], char t[]) {
    int i, j = 0;

    while (t[i] != '\0') { 
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
    s[i] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j = 0;
    
    while (t[i] != '\0') {
        if (t[i] == '\\') {
            switch (t[i+1]) {
                case 'n':
                    s[j++] = '\n';
                    i++;
                    break;
                case 't':
                    s[j++] = '\t';
                    i++;
                    break;
                default:
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
        i++;
    }
    s[i]='\0';
}

int main() {
    char t[] = "Hello\tWorld\n";
    char s[100];
    escape(s, t);
    printf("Escaped: %s \n", s);



    char t2[] = "Hello\\tWorld\\n";
    char s2[100000];
    unescape(s2, t2);
    printf("Unescaped: %s", s2);

    return 0;
}