#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

void calculateFactorials(int array[], int size) {
    for (int i = 0; i < size; i++) {
        int result = factorial(array[i]);
        printf("Silnia dla liczby %d wynosi: %d\n", array[i], result);
    }
}

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(array) / sizeof(array[0]);

    calculateFactorials(array, size);

    return 0;
}