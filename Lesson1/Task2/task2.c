#include <stdio.h>

int main() {
    // Array of grades for 2 subjects
    float grades[2][3] = {
        {4.5, 3.0, 5.0},
        {3.5, 4.0, 4.5}
    };

    // Average grade for subjects
    for (int i = 0; i < 2; i++) {
        float sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += grades[i][j];
        }
        printf("Average grade for subject %d: %.2f\n", i + 1, sum / 3);
    }

    return 0;
}