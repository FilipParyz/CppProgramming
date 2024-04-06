#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generatePermutations(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            int isDuplicate = 0;
            for (int j = start; j < i; j++) {
                if (arr[j] == arr[i]) {
                    isDuplicate = 1;
                    break;
                }
            }
            if (!isDuplicate) {
                swap(&arr[start], &arr[i]);
                generatePermutations(arr, start + 1, end);
                swap(&arr[start], &arr[i]);
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    generatePermutations(arr, 0, n - 1);

    return 0;
}