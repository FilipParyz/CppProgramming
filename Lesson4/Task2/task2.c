#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        return binarySearch(arr, mid + 1, right, target);
    }
    return -1;
}

void fillArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 100;
    }
}

void sortArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int tableLength;
    printf("Podaj długość tabeli: ");
    scanf("%d", &tableLength);

    int arr[tableLength];
    srand((unsigned int)time(0));
    
    fillArray(arr, tableLength);
    sortArray(arr, tableLength);

    printf("\nTabela:\n");
    for (int i = 0; i < tableLength; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n\n");

    int searchedNumber = rand() % 100;
    printf("Poszukiwana liczba: %d\n", searchedNumber);

    int result = binarySearch(arr, 0, tableLength - 1, searchedNumber);
    if (result == -1)
        printf("Element nie został znaleziony w tablicy.\n");
    else
        printf("Element znaleziony na pozycji %d.\n", result);

    return 0;
}