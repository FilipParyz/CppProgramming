#include <stdio.h>

void doubleValue(float *ptr) {
    *ptr /= 2;
}

int main() {
    float number = (float)42.74;
    printf("Wartość przed modyfikacją: %.2f\n", number);
    
    doubleValue(&number);
    
    printf("Wartość po modyfikacji: %.2f\n", number);
    
    return 0;
}