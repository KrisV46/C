#include <stdio.h>
#include <string.h>

int main() {
    char input_str[100];
    int words_count = 0;

    printf("Enter words: ");
    fgets(input_str, sizeof(input_str), stdin);

    for(int i = 0; i < strlen(input_str); i++) {
        if(input_str[i] == ' ' || input_str[i] == '\n') {
            words_count++;
        }
    }

    printf("The count of the words: %d\n", words_count);
    return 0;
}
