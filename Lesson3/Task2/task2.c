#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;
    
    printf("Podaj liczbę wierszy: ");
    scanf("%d", &rows);
    
    printf("Podaj liczbę kolumn: ");
    scanf("%d", &cols);
    
    size_t int_pointer_size = sizeof(int*);
    size_t int_size = sizeof(int);

    int** matrix = (int**)malloc((size_t)(rows) * int_pointer_size);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc((size_t)(cols) * int_size);
    }
    
    srand((unsigned int)time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (rand() % 100)+1;
        }
    }
    
    printf("Zawartosc macierzy:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}