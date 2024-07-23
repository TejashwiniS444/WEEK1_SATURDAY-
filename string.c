//C PROGRAM TO FIND NUMBER OF VOWELS
#include <stdio.h>
#include <ctype.h>

int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int countVowels(const char *str) {
    int count = 0;
    while (*str) {
        if (isVowel(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int numVowels = countVowels(str);

    printf("Number of vowels: %d\n", numVowels);

    return 0;
}
