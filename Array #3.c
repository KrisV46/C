#include <stdio.h>

int main(){
    int arr[7];
    int i, average, suma = 0;
    for(i = 0; i<7; i++){
    printf("Enter numbers: ");
    scanf("\n%d", &arr[i]);
    suma += arr[i];
    }
//printf("Sumata %d", suma);
average = suma / 7;
printf("%d", average);
return 0;
}
