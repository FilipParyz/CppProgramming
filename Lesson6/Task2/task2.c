#include <stdio.h>

int main() {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr = array;

    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n", i, *ptr);
        ptr++;
    }

    return 0;
}