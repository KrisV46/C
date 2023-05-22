#include <stdio.h>

int main() {
    int num1, num2, sum = 0;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Ако първото число е по-голямо, разменяме ги
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    // Сумираме числата между num1 и num2
    for (int i = num1 + 1; i < num2; i++) {
        sum += i;
    }

    printf("Sum of integers between %d and %d is %d", num1, num2, sum);

    return 0;
}
