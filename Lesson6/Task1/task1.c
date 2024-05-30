#include <stdio.h>

union Onion {
    int _int;
    float _float;
    char _char;
};

void print_onion(union Onion onion) {
    printf("\nValue int: %d\n", onion._int);
    printf("Value float: %ff\n", onion._float);
    printf("Value char: '%c'\n", onion._char);
}

int main() {
    union Onion myOnion = {0};

    myOnion._int = 65;
    printf("\nSet int to 65.");
    print_onion(myOnion);

    myOnion._float = 3.14f;
    printf("\nSet float to 3.14.");
    print_onion(myOnion);

    myOnion._char = 'A';
    printf("\nSet char to 'A'.");
    print_onion(myOnion);

    return 0;
}