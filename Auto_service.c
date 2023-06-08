#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Auto{
char name[36];
char num_plate[9];
float price;
int priority;
};

int numCars = 0;
void addAuto(struct Auto** car){
    struct Auto newCar;
    printf("Enter name: ");
    fgets(newCar.name,sizeof(newCar.name),stdin);
    strtok(newCar.name, "\n");

    printf("Enter num plate: ");
    fgets(newCar.num_plate, sizeof(newCar.num_plate),stdin);
    strtok(newCar.num_plate, "\n");

    printf("Enter the price: ");
    scanf("%f", &newCar.price);
    getchar();

    int priority;
    while(1){
        printf("Enter priority: ");
        scanf("%d", &priority);
        getchar();

        if(priority >=1 && priority<=5){
            newCar.priority = priority;
            break;
        }else{
            printf("Wrong priority. \n");
        }

    }
    *car = realloc(*car, (numCars+1) * sizeof(struct Auto));
    /*if(*car == NULL){
        printf("Error ");
        exit(1);
    }*/

    (*car)[numCars++] = newCar;


    FILE *fileptr = fopen("autoText.txt", "a");
    if (fileptr == NULL){
        printf("Error opening");
        exit(1);
    }

    fprintf(fileptr, "%zu; %s; %s; %.2f; %d;", strlen(newCar.name), newCar.name, newCar.num_plate, newCar.price, newCar.priority);
    fclose(fileptr);
}
float totalPrice = 0.0;

void average(struct Auto car[], int numCars){

for (int i = 0; i< numCars; i++){
    totalPrice += car[i].price;
}
float average_price = totalPrice / numCars;

for(int j = 0; j<numCars; j++){
    if(car[j].price > average_price){
        printf("%s - %.2f\n", car[j].num_plate, car[j].price);
    }
}
}

void search_by_plate(char num_plate, int numCars){
    FILE* fileptr = fopen("auto.bin", "rb");
    if(fileptr == NULL){
        printf("Error opening! \n");
        exit(1);
    }
    struct Auto newCar;

    while(fread(&newCar, sizeof(struct Auto),1, fileptr)==1){
        if(strcmp(newCar.num_plate,num_plate) == 0){
            printf("Bin Name:%s Bin L_Plate:%s Bin Price:%f Bin Priority:%d", newCar.name, newCar.num_plate, newCar.price, newCar.priority);
            break;
        }else{
        printf("Not found! ");

        }
            }
     fclose(fileptr);
    }



int main(){
    struct Auto *car = NULL;
    //int numCars = 0;
    int choice;

    while(choice != 2){
        printf("Choose an option:\n");
        printf("1. Add a member\n");
        printf("2. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                addAuto(&car);
                break;
            case 2:
                printf("Goodbye \n");
                break;
            default:
                printf("Invalid choice. \n");
                break;
        }
    }
    average(car,numCars);

    char num_plate[9];
    printf("Enter plate num: ");
     fgets(num_plate, sizeof(num_plate), stdin);
     strtok(num_plate, "\n");

    search_by_plate(num_plate, numCars);

    free(car);
    return 0;
}
