#include <stdio.h>
#include <string.h>
struct Vehicle_shop_info{
    char brand[30];
    int year;
    char model[30];
};
int main(){

    struct Vehicle_shop_info car[3];

    for(int i = 0; i < 3; i++){
        printf("Enter the brand: ");
        scanf("%s", car[i].brand);
        printf("Enter the year: ");
        scanf("%d", &car[i].year);
        printf("Enter model:");
        scanf("%s", car[i].model);
    }

    for(int i = 0; i < 3; i++){
        printf("%s, %d, %s\n ", car[i].brand,car[i].year, car[i].model);
    }


return 0;
}
