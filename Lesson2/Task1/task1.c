#include <stdio.h>

int main() {
    int value = 10;
    int *pointer = &value;

    printf("Wartość zmiennej: %d\n", value);
    printf("Wartość zmiennej przez wskaźnik: %d\n", *pointer);

    *pointer = 20;

    printf("Po modyfikacji:\n");
    printf("Wartość zmiennej: %d\n", value);
    printf("Wartość zmiennej przez wskaźnik: %d\n", *pointer);

    return 0;
}