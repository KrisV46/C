#include <stdio.h>
int main(){

int n,m;
printf("Enter the first number: ");
scanf("%d", &n);
printf("Enter the second number: ");
scanf("%d", &m);
int sum = n + m;
int mult = n * m;
if(n && m %2 == 0){
printf ("%d + %d = %d ", m,n,sum);
}
else if(n && m %2 !=0){
printf ("%d * %d = %d ", m,n,mult);
}

return 0;
}
