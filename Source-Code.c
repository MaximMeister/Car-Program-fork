// Made in Germany
// by Phil Reinartz, Maxim Meister, Laurenz Wrobel, Georg Kulodzik and Mikail Erarslan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[64];
    int age;
    float retail_price;
    int sales_price;
    void* prev;
    void* next;

} car_t;

typedef struct {
    car_t* start;
    car_t* end;

} list;

list carslist;

// PURPOSE:
// Creates a car from the users input.

car_t* create_car() {
    car_t* newcar = malloc(sizeof(car_t));
    if (!newcar) {
        printf("Not possible to allocate\n");
        exit(1);
    }
    char name[64];
    int age;
    float price;
    printf("Name:");
    scanf(" %10s", name);
    printf("\nAge:");
    scanf(" %i", &age);
    printf("\nRetail price:");
    scanf(" %f", &price);
    strcpy(newcar->name, name);  // This function is used to copy the string
    newcar->age = age;
    newcar->retail_price = price;
    return newcar;
}

// PURPOSE:
// Adds another car to the end of the list.

void add_car_to_end(car_t* actualcar) {
    actualcar->next = NULL;
    actualcar->prev = carslist.end;

    if (carslist.end) {
        carslist.end->next = actualcar;
    } else {
        carslist.start = actualcar;
    }

    carslist.end = actualcar;
}

// PURPOSE:
// Prints all cars of the existing list.

void print_list() {
    if (!carslist.end) {
        printf("Empty list\n");
    }
    car_t* p = carslist.start;

    while (p != NULL) {
        printf("Name: %s\n", p->name);
        printf("Age: %i\n", p->age);
        printf("Retail price: %.2f€\n\n", p->retail_price);
        p = p->next;
    }
}

// PURPOSE:
// Frees the heap from the list.

void delete_list() {
    car_t* p = carslist.start;
    while (p) {
        car_t* next = p->next;
        free(p);
        p = next;
    }
    carslist.start = NULL;
    carslist.end = NULL;
}

// PURPOSE:
// Defines the start and the endpoint and starts the user CLI for interaction with the program.

int main() {
    carslist.start = NULL;
    carslist.end = NULL;

    car_t* car;
    char choice;
    while (1) {
        printf(
            "Choose option:\n"
            "(1) Create a car and insert at the end\n"
            "(2) Print list\n"
            "(3) Delete cars\n"
            "(q) Quit\n\n\n");

        printf("Type option :");
        scanf(" %c", &choice);
        printf(
            "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            "\n\n\n");
        switch (choice) {
            case '1':
                car = create_car();

                add_car_to_end(car);

                break;

            case '2':
                print_list();
                break;

            case '3':
                delete_list();

                break;

            case 'q':
                delete_list();
                return 0;

            default:
                printf("Wrong character!\n");
        }
    }

    return 0;
}
