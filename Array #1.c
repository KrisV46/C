#include <stdio.h>

int main (){
int suma = 0;
int arr[7];

for(int i = 0; i<7; i++){
printf("Vuvedete chisla: ");
scanf("%d", &arr[i]);

while(arr[i] <-5000 || arr[i] >5000){
printf("Invalid number!! \n");
printf("Enter a new number: ");
scanf("%d", &arr[i]);
}
suma += arr[i];
}
printf("Proizvedenieto na chislata e: %d", suma);
return 0;
}

