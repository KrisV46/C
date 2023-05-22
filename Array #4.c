#include <stdio.h>
#include <stdlib.h>
int main(){
    int arr[7], i;
    float average, sum = 0;
    int closest_num = arr[0];


    for (i = 0; i < 7; i++){
        printf("Enter a number: ");
        scanf("%d", &arr[i]);
        sum += arr[i];

    }
    average = sum / 7;

    for (i = 0; i < 7; i++){
       if(abs(arr[i] - average) < abs(closest_num - average)) {
         closest_num = arr[i];
      }

    }


    printf("The closest number to %.3f is %d.\n", average, closest_num);

    for (i = 0; i < 7; i++){
        if(arr[i] == closest_num){
            printf("The index is %d", i);
        }
    }

    return 0;
}
