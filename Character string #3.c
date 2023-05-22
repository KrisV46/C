#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i]; i++){
        str[i]=toupper(str[i]);


    }
    printf("%s", str);

    return 0;
}
