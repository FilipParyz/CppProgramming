#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int a, b;
    int (*functionPointer)(int, int);

    printf("Input two intigers divided with a space: ");
    scanf("%d %d", &a, &b);

    int choice;
    printf("Select operation:\n1. Add\n2. Multiply\n3. Subtract\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            functionPointer = add;
            break;
        case 2:
            functionPointer = multiply;
            break;
        case 3:
            functionPointer = subtract;
            break;
        default:
            printf("Wrong choice.\n");
            return 1;
    }

    int result = functionPointer(a, b);
    printf("Result: %d\n", result);

    return 0;
}