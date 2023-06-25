

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Picture{
    int code;
    char name[31];
    char title[31];
    float price;
};

float above_average(struct Picture * pictures, int n, float price){
    float total_sum = 0.0;
    int count = 0;
    for(int i = 0; i<n; i++){
        if(pictures[i].price>price){
            count++;
            total_sum += pictures[i].price;
        }
    }
    if(count > 0){
        return total_sum / count;
    }else{
        return 0.0;
        }
}

int save_to_file(struct Picture* pictures, int n, char letter){
    FILE *fileptr = fopen("infooooooo.txt", "a");
    if(fileptr == NULL){
        perror("Error opening the file! ");
        return 0;
    }
    int count = 0;
    for (int i = 0; i<n; i++){
        if(pictures[i].name[0]==letter){
            count++;
            fprintf(fileptr, "%d; %s; %.2fleva\n", pictures[i].code, pictures[i].title, pictures[i].price);
            }
    }
    fclose(fileptr);
    if(count>0){
        return count;
    } else{
        return 0;
        }
}
void from_bin(char* artname){
    FILE *fileptr = fopen("info.bin", "rb");
    if(fileptr == NULL){
        perror("Error opening the file! ");
        exit(1);
}
    int ucode,nameLen,titleLen;
    struct Picture picture;

    while(fread(&ucode,sizeof(int),1,fileptr)==1){
        fread(&nameLen, sizeof(int),1,fileptr);
        fread(picture.name,sizeof(picture.name),nameLen, fileptr);
        picture.name[nameLen] = '\0';

        fread(&titleLen, sizeof(int), 1, fileptr);
        fread(picture.title, sizeof(char), titleLen, fileptr);
        picture.title[titleLen] = '\0';

        fread(&picture.price, sizeof(double), 1, fileptr);

        if(strcmp(picture.name,artname)==0){
            printf("Уникален код: %d\n", picture.code);
            printf("Име на художника: %s\n", picture.name);
            printf("Название на картината: %s\n", picture.title);
            printf("Цена: %.2f\n", picture.price);
        }else{
            printf("No matches");
            exit(1);
            }
    }
}

int main(){
    int n;
    printf("Enter the number of pictures: ");
    scanf("%d", &n);

    if (n < 1 || n > 30) {
        printf("Invalid number of pictures!\n");
        return 0;
    }

    struct Picture* pictureArray = (struct Picture*)calloc(n, sizeof(struct Picture));
    if(pictureArray == NULL){
        perror("Error alocating the memory! ");
        return 0;
    }
    for(int i = 0; i<n; i++){
        printf("Unique code: ");
        scanf("%d", &(pictureArray[i].code));
        getchar();
        printf("Artist name: ");
        scanf("%s", pictureArray[i].name);
        getchar();
        printf("Title: ");
        fgets(pictureArray[i].title, sizeof(pictureArray[i].title), stdin);
        fflush(stdin);
        printf("Price: ");
        scanf("%f", &(pictureArray[i].price));
        getchar();
    }
    float price;
    printf("Enter a price to calculate above: ");
    scanf("%f", &price);
    getchar();
    float averageP = above_average(pictureArray, n, price);
    printf("The average price above %.2f is: %.2f\n", price, averageP);


    char letter;
    printf("Enter a letter: ");
    scanf("%c", &letter);
    getchar();

    int count = save_to_file(pictureArray, n, letter);
    printf("Items saved to file: %d\n", count);

    char artName[31];
    printf("Enter an artis name: ");
    fgets(artName, sizeof(artName),stdin);
    fflush(stdin);

    from_bin(artName);

    free(pictureArray);
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Picture {
    int code;
    char artist[30];
    char title[30];
    double price;
};


double averagePrice(struct Picture* array, int size, double price) {
    int count = 0;
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        if (array[i].price > price) {
            count++;
            sum += array[i].price;
        }
    }

    if (count > 0) {
        return sum / count;
    } else {
        return 0.0;
    }
}

int saveToFile(struct Picture* array, int size, char letter) {
    FILE* filePtr = fopen("info.txt", "w");
    if (filePtr == NULL) {
        printf("Error opening the file!\n");
        return 0;
    }

    int count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i].artist[0] == letter) {
            fprintf(filePtr, "%d; %s; %.2lfleva\n", array[i].code, array[i].title, array[i].price);
            count++;
        }
    }

    fclose(filePtr);
    if(count>0){
        return count;
    }else{
        return 0;
        }

}

void printArtistPaintings(char artistName) {
    FILE* file = fopen("picture.bin", "rb");
    if (file == NULL) {
        printf("Error opening the file!\n");
        return;
    }

    int found = 0;
    int code, artistLength, titleLength;
    while (fread(&code, sizeof(int), 1, file) == 1) {
        struct Picture picture;

        fread(&artistLength, sizeof(int), 1, file);
        fread(picture.artist, sizeof(char), artistLength, file);
        //picture.artist[artistLength] = '\0';

        fread(&titleLength, sizeof(int), 1, file);
        fread(picture.title, sizeof(char), titleLength, file);
        //picture.title[titleLength] = '\0';

        fread(&picture.price, sizeof(double), 1, file);

        if (strcmp(picture.artist, artistName) == 0) {
            printf("Уникален код: %d\n", picture.code);
            printf("Име на художника: %s\n", picture.artist);
            printf("Название на картината: %s\n", picture.title);
            printf("Цена: %.2f\n", picture.price);
            printf("-----------------\n");
            found = 1;
            //break;
        }
    }
    if (!found) {
        printf("Няма намерен\n");
    fclose(file);
    //break;
}
}

int main() {
    int n;
    printf("Enter the number of pictures: ");
    scanf("%d", &n);

    if (n <= 3 || n >= 30) {
        printf("Invalid number of pictures!\n");
        return 0;
    }


    struct Picture* pictureArray = (struct Picture*)calloc(n, sizeof(struct Picture));
    if (pictureArray == NULL) {
        printf("Error allocating memory!\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter information for picture %d:\n", i + 1);
        printf("Unique code: ");
        scanf("%d", &(pictureArray[i].code));
        printf("Artist name: ");
        scanf("%s", pictureArray[i].artist);
        printf("Title: ");
        getchar();  // Consume the newline character left in the input buffer
        fgets(pictureArray[i].title, sizeof(pictureArray[i].title), stdin);
        pictureArray[i].title[strlen(pictureArray[i].title)-1]='\0';  // Remove the newline character from the title
        printf("Price: ");
        scanf("%lf", &(pictureArray[i].price));
    }


    //fillArray(pictureArray, n);

    double price;
    printf("Enter the price: ");
    scanf("%lf", &price);

    double avgPrice = averagePrice(pictureArray, n, price);
    printf("Average price of pictures more expensive than %.2lf: %.2lf\n", price, avgPrice);

    char letter;
    printf("Enter a letter: ");
    scanf(" %c", &letter);

    int savedCount = saveToFile(pictureArray, n, letter);
    printf("Elements saved to the file: %d\n", savedCount);

    char artistName[30];
    printf("Enter the artist name: ");
    scanf("%s", artistName);

    printArtistPaintings(artistName);

    free(pictureArray);

    return 0;
}
*/
