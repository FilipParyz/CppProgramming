#include <stdio.h>

int factorial(int n) {
    printf("n = %d\n", n);
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num = 8;
    int result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);
    return 0;
}