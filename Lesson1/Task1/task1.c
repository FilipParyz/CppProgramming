#include <stdio.h>

int main() {
    char imie[20];
    printf("Jak masz na imię?\n");
    scanf("%s", imie);
    printf("Cześć, %s\n", imie);
    return 0;
}