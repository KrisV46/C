
#include <stdio.h>

int main (){
int i;
int max_num = -5001;
int arr[7];

for(i = 0; i<7; i++){
printf("Vuvedete chisla: ");
scanf("%d", &arr[i]);


if (max_num < arr[i]){
    max_num = arr[i];
    //printf("Biggest number is: %d", arr[i]);
}
}
printf("Biggest number is: %d", max_num);
return 0;
}
