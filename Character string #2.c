#include <stdio.h>
#include <ctype.h>

void count_and_print_vowels(const char str[]) {
    int count = 0;

    printf("Vowels: ");
    for (int i = 0; str[i]; i++) {
        switch (tolower(str[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'y':
                printf("%c ", str[i]);
                count++;
                break;
            default:
                break;
        }
    }

    printf("\nCount: %d\n", count);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    count_and_print_vowels(str);

    return 0;
}
