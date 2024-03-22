#include <stdio.h>
#include <stdlib.h>

void printPascalTriangle(int height) {

    int** triangle = (int**)malloc((long unsigned int)height * sizeof(int*));

    for (int i = 0; i < height; i++) {
        triangle[i] = (int*)malloc((long unsigned int)(i + 1) * sizeof(int));
        triangle[i][0] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle[i][i] = 1;
    }

    int cellWidth = 5;
    int totalWidth = height * cellWidth;
    for (int i = 0; i < height; i++) {
        int padding = (totalWidth - (i+1)*cellWidth) / 2;
        for (int j = 0; j < padding; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%*d", cellWidth, triangle[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

int main() {
    int N;
    printf("Podaj wysokość trójkąta Pascala: ");
    scanf("%d", &N);

    printPascalTriangle(N);

    return 0;
}