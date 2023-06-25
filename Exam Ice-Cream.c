#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IceCream {
    char code[4]; // Increased the size to accommodate null terminator
    char name[21]; // Increased the size to accommodate null terminator
    int weight;
    float price;
};

float totalIceCreamPrice(struct IceCream* arr, int n, char letter) {
    float totalPrice = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i].name[0] == letter) {
            totalPrice += arr[i].weight * arr[i].price;
        }
    }
    return totalPrice;
}

int saveIceCreamToFile(struct IceCream* arr, int n, float maxPrice, int minWeight) {
    FILE* file = fopen("info.txt", "w");
    if (file == NULL) {
        printf("Error opening the file!\n");
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].price < maxPrice && arr[i].weight > minWeight) {
            fprintf(file, "%s; %s; %d; %.2fleva\n", arr[i].code, arr[i].name, arr[i].weight, arr[i].price);
            count++;
        }
    }

    fclose(file);
    return count;
}

void printIceCreamByCode(char* code) {
    FILE* file = fopen("icecream.bin", "rb");
    if (file == NULL) {
        printf("Error: Failed to open the file!\n");
        return;
    }

    int found = 0;
    char currCode[3]; // Increased the size to accommodate null terminator
    int nameLength;

    struct IceCream icecream;

    while (fread(currCode, sizeof(char), 3, file) == 3) {
        //currCode[3] = '\0'; // Added null terminator

        fread(&nameLength, sizeof(int), 1, file);
        fread(icecream.name, sizeof(char), nameLength, file);
        icecream.name[nameLength] = '\0';

        fread(&icecream.weight, sizeof(int), 1, file);
        fread(&icecream.price, sizeof(float), 1, file);

        if (strcmp(currCode, code) == 0) {
            printf("IceCream - %s\n", icecream.name);
            printf("Price - %.2f BGN\n", icecream.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Ice cream with code %s not found!\n", code);
    }

    fclose(file);
}

int main() {
    int n;
    printf("Enter the number of ice creams: ");
    scanf("%d", &n);

    if (n < 1 || n > 15) {
        printf("Invalid number of ice creams! The number should be between 1 and 15.\n");
        return 0;
    }

    struct IceCream* iceCreams = (struct IceCream*)malloc(n * sizeof(struct IceCream));
    if (iceCreams == NULL) {
        printf("Error allocating memory!\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter data for ice cream %d:\n", i + 1);
        printf("Code: ");
        scanf("%s", iceCreams[i].code);
        printf("Product name: ");
        scanf(" %[^\n]s", iceCreams[i].name);
        printf("Weight: ");
        scanf("%d", &iceCreams[i].weight);
        printf("Price: ");
        scanf("%f", &iceCreams[i].price);
    }

    char letter;
    printf("Enter a letter: ");
    scanf(" %c", &letter);

    float totalPrice = totalIceCreamPrice(iceCreams, n, letter);
    printf("Total price of ice creams whose names start with the letter %c: %.2f BGN\n", letter, totalPrice);

    float maxPrice;
    int minWeight;
    printf("Enter the maximum price: ");
    scanf("%f", &maxPrice);
    printf("Enter the minimum weight: ");
    scanf("%d", &minWeight);

    int savedCount = saveIceCreamToFile(iceCreams, n, maxPrice, minWeight);
    if (savedCount > 0) {
        printf("Information for %d ice cream(s) has been saved to the info.txt file.\n", savedCount);
    } else {
        printf("No ice creams matching the criteria were found.\n");
    }

    char code[3]; // Increased the size to accommodate null terminator
    printf("Enter an ice cream code: ");
    scanf("%s", code);

    printIceCreamByCode(code);

    free(iceCreams);

    return 0;
}












/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for IceCream
struct IceCream {
    char code[3];
    char name[20];
    int weight;
    double price;
};

// Function to fill the array with IceCream data
void fillArray(struct IceCream* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter information for IceCream %d:\n", i + 1);
        printf("Unique code (e.g., A2): ");
        scanf("%s", array[i].code);
        printf("Name: ");
        scanf("%s", array[i].name);
        printf("Weight (kg): ");
        scanf("%d", &(array[i].weight));
        printf("Price per kilogram: ");
        scanf("%lf", &(array[i].price));
    }
}

// Function to calculate the total price of IceCreams starting with a given letter
double totalPriceByLetter(struct IceCream* array, int size, char letter) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        if (array[i].name[0] == letter) {
            total += array[i].price * array[i].weight;
        }
    }
    return total;
}

// Function to save IceCreams with specified price and weight to a text file
int saveToFile(struct IceCream* array, int size, double price, int weight) {
    FILE* filePtr = fopen("info.txt", "w");
    if (filePtr == NULL) {
        printf("Error opening the file!\n");
        return 0;
    }

    int count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i].price < price && array[i].weight > weight) {
            fprintf(filePtr, "%s; %s; %d; %.2fleva\n", array[i].code, array[i].name, array[i].weight, array[i].price);
            count++;
        }
    }

    fclose(filePtr);
    return count;
}

// Function to print IceCream information by code from a binary file
void printIceCreamByCode(char* code) {
    FILE* filePtr = fopen("icecream.bin", "rb");
    if (filePtr == NULL) {
        printf("Error opening the file!\n");
        return;
    }

    struct IceCream iceCream;

    while (fread(&iceCream, sizeof(struct IceCream), 1, filePtr) == 1) {
        if (strcmp(iceCream.code, code) == 0) {
            printf("IceCream - %s\n", iceCream.name);
            printf("Price - %.2f BGN\n", iceCream.price);
            fclose(filePtr);
            return;
        }
    }

    printf("No IceCream found with code %s\n", code);
    fclose(filePtr);
}

int main() {
    int n;
    printf("Enter the number of IceCreams: ");
    scanf("%d", &n);

    if (n <= 5 || n >= 15) {
        printf("Invalid number of IceCreams!\n");
        return 0;
    }

    struct IceCream* iceCreamArray = (struct IceCream*)malloc(n * sizeof(struct IceCream));
    if (iceCreamArray == NULL) {
        printf("Error allocating memory!\n");
        return 0;
    }

    fillArray(iceCreamArray, n);

    char letter;
    printf("Enter a letter: ");
    scanf(" %c", &letter);

    double totalByLetter = totalPriceByLetter(iceCreamArray, n, letter);
    printf("Total price of IceCreams starting with '%c': %.2f\n", letter, totalByLetter);

    double price;
    int weight;
    printf("Enter price and weight criteria:\n");
    printf("Price: ");
    scanf("%lf", &price);
    printf("Weight: ");
    scanf("%d", &weight);

    int savedCount = saveToFile(iceCreamArray, n, price, weight);
    printf("Elements saved to the file: %d\n", savedCount);

    char code[3];
    printf("Enter the IceCream code: ");
    scanf("%s", code);

    printIceCreamByCode(code);

    free(iceCreamArray);

    return 0;
}
*/
