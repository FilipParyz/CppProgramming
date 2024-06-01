#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stringToDigit(char *str) {
    if (strstr(str, "one")) return 1;
    if (strstr(str, "two")) return 2;
    if (strstr(str, "three")) return 3;
    if (strstr(str, "four")) return 4;
    if (strstr(str, "five")) return 5;
    if (strstr(str, "six")) return 6;
    if (strstr(str, "seven")) return 7;
    if (strstr(str, "eight")) return 8;
    if (strstr(str, "nine")) return 9;
    return -1;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Nie mogę otworzyć pliku.\n");
        return 1;
    }

    int suma = 0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int firstDigit = -1;
        int lastDigit = -1;
        char word[256] = "";
        for (int i = 0; line[i] != '\0'; i++) {
            if (isdigit((unsigned char)line[i])) {
                if (firstDigit == -1) {
                    firstDigit = line[i] - '0';
                }
                lastDigit = line[i] - '0';
            } else if (isalpha((unsigned char)line[i])) {
                int len = (int)strlen(word);
                word[len] = line[i];
                word[len + 1] = '\0';
                int digit = stringToDigit(word);
                if (digit != -1) {
                    if (firstDigit == -1) {
                        firstDigit = digit;
                    }
                    lastDigit = digit;
                    word[0] = '\0';
                }
            }
        }
        int digit = stringToDigit(word);
        if (digit != -1 && firstDigit != -1) {
            lastDigit = digit;
        }
        if (firstDigit != -1 && lastDigit != -1) {
            suma += firstDigit * 10 + lastDigit;
        }
    }

    fclose(file);

    printf("Suma wszystkich wartości energetycznych to: %d\n", suma);

    return 0;
}