#include <stdio.h>
void even_or_odd(int number){
if (number % 2 == 0){
    printf("The number is odd", number);
}
else {
    printf("The number is even", number);

    }
}
 int main(){
 int n;

 printf("Enter a number: ");
 scanf("%d", &n);
 even_or_odd(n);
 return 0;
}
int main(){
   // int n1;
//printf("Enter a number: ");
//scanf("%d", &n1);
even_or_odd(5/*n1*/);
return 0;
}
