#include <stdio.h>

struct Car {
    char model[50];
    int year;
    float mileage;
};

int main() {
    struct Car cars[4];

    printf("Enter details of 4 cars: ");

    for (int i=0; i<4; i++) {
        printf("Car %d:\n", i+1);

        printf("Model: ");
        scanf(" %[^\n]", cars[i].model);

        printf("Year: ");
        scanf("%d", &cars[i].year);

        printf("Mileage: ");
        scanf("%f", &cars[i].mileage);

    }

    printf("\nCars with mileage >= 15.0 km/l:\n");

    for (int i=0; i<4; i++) {
        if(cars[i].mileage>=15.0) {
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Mileage: %.1f\n", cars[i].mileage);
        }
    }

    return 0;
}
