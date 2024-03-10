#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROUNDS 10
#define MAX_NAME_LENGTH 20

typedef enum { PAPER, ROCK, SCISSORS } Move;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Move move;
} Player;

typedef struct {
    Player player1;
    Player player2;
    int player1Score;
    int player2Score;
} Round;

void initializeRound(Round *round) {
    round->player1Score = 0;
    round->player2Score = 0;
}

void playRound(Round *round) {
    printf("Gracz 1, wpisz swoje imię: ");
    scanf("%s", round->player1.name);

    printf("Gracz 2, wpisz swoje imię: ");
    scanf("%s", round->player2.name);

    printf("%s, wybierz ruch (0 - papier, 1 - kamień, 2 - nożyce): ", round->player1.name);
    scanf("%d", (int *)&(round->player1.move));

    printf("%s, wybierz ruch (0 - papier, 1 - kamień, 2 - nożyce): ", round->player2.name);
    scanf("%d", (int *)&(round->player2.move));

    if (round->player1.move == round->player2.move) {
        printf("Remis!\n");
    } else if ((round->player1.move == PAPER && round->player2.move == ROCK) ||
               (round->player1.move == ROCK && round->player2.move == SCISSORS) ||
               (round->player1.move == SCISSORS && round->player2.move == PAPER)) {
        printf("%s wygrywa!\n", round->player1.name);
        round->player1Score++;
    } else {
        printf("%s wygrywa!\n", round->player2.name);
        round->player2Score++;
    }
}

void printScores(Round *rounds, int numRounds) {
    printf("Wyniki:\n");
    for (int i = 0; i < numRounds; i++) {
        printf("Runda %d: %s: %d, %s: %d\n", i + 1, rounds[i].player1.name, rounds[i].player1Score,
               rounds[i].player2.name, rounds[i].player2Score);
    }
}

int main() {
    Round rounds[MAX_ROUNDS];
    int numRounds = 0;
    char command[10];

    initializeRound(&rounds[numRounds]);

    while (1) {
        printf("Wpisz komendę (play - zagraj rundę, scores - wyświetl wyniki, exit - wyjście): ");
        scanf("%s", command);

        if (strcmp(command, "play") == 0) {
            if (numRounds < MAX_ROUNDS) {
                playRound(&rounds[numRounds]);
                numRounds++;
            } else {
                printf("Osiągnięto maksymalną liczbę rund!\n");
            }
        } else if (strcmp(command, "scores") == 0) {
            printScores(rounds, numRounds);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Nieznana komenda!\n");
        }
    }

    return 0;
}