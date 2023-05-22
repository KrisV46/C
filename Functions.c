#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float square(float a){
return a*a;
}
float rectangle(float a, float b){
return a*b;
}
float right_triangle(float a, float b){
return (a*b)/2;
}
float circle(float r){
return M_PI * r * r;
}
int main(){
int figure;
float a,b,r;

printf("Enter the figure code: ");
scanf("%d", &figure);

switch(figure){
    case 1:
        printf("Enter the side of the square: ");
        scanf("%f", &a);
        printf("The area of the square is: %.2f", square(a));
        break;

    case 2:
        printf("Enter the sides of the rectangle: ");
        scanf("%f", &a, &b);
        printf("The are of the rectangle is: %f", rectangle(a,b));
        break;
    case 3:
        printf("Enter the sides of the right_triangle: ");
        scanf("%f",&a, &b);
        printf("The area of the right_triangle: %f", right_triangle(a,b));
        break;
    case 4:
         printf("Enter the radius of the circle: ");
         scanf("f", &r);
         printf("The are of the circle: %f", circle(r));
         break;

}
return 0;
}
