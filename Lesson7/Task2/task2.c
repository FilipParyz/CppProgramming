#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int red[10];
    int green[10];
    int blue[10];
    int rounds;
} Game;

void read_games_from_file(const char* filename, Game* games, int* game_count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Game game;
        sscanf(line, "Game %d", &game.id);

        int round = 0;
        char* token = strtok(line, ":");
        token = strtok(NULL, ";");
        while (token != NULL) {
            int value1 = 0, value2 = 0, value3 = 0;
            int place_red = 256, place_green = 256, place_blue = 256;

            sscanf(token, "%d %*[a-z,] %d %*[a-z,] %d %*[a-z]", &value1, &value2, &value3);
            
            if (strstr(token, "red")){
                place_red = (int)(strstr( token, "red") - token); 
            }
            if (strstr(token, "green")){
                place_green = (int)(strstr( token, "green") - token);
            }
            if (strstr(token, "blue")){
                place_blue = (int)(strstr( token, "blue") - token);
            }

            if ( place_red != 256 ){
                if (    place_red < place_green
                    &&  place_red < place_blue){
                    game.red[round] = value1;
                } else if (     place_red < place_green
                            ||  place_red < place_blue){
                    game.red[round] = value2;
                } else {
                    game.red[round] = value3;
                }
            } else {
                game.red[round] = 0;
            }
            if ( place_green != 256 ){
                if (    place_green < place_red
                    &&  place_green < place_blue){
                    game.green[round] = value1;
                } else if (     place_green < place_red
                            ||  place_green < place_blue){
                    game.green[round] = value2;
                } else {
                    game.green[round] = value3;
                }
            } else {
                game.green[round] = 0;
            }
            if ( place_blue != 256 ){
                if (    place_blue < place_red
                    &&  place_blue < place_green){
                    game.blue[round] = value1;
                } else if (     place_blue < place_red
                            ||  place_blue < place_green){
                    game.blue[round] = value2;
                } else {
                    game.blue[round] = value3;
                }
            } else {
                game.blue[round] = 0;
            }
            
            round++;
            token = strtok(NULL, ";");
        }
        game.rounds = round;

        games[*game_count] = game;
        (*game_count)++;
    }

    fclose(file);
}

int main() {
    Game games[100];
    int game_count = 0;
    read_games_from_file("input.txt", games, &game_count);

    int sum = 0;
    for (int i = 0; i < 100; i++) {
        int possible = 1;
        int sum_red = 0, sum_green = 0, sum_blue = 0;
        for (int j = 0; j < games[i].rounds; j++) {
            sum_red += games[i].red[j];
            sum_green += games[i].green[j];
            sum_blue += games[i].blue[j];
            if (sum_red > 12 || sum_green > 13 || sum_blue > 14) {
                possible = 0;
                break;
            }
        }

        if (possible) {
            printf("Możliwa gra: %d\n", games[i].id);
            printf("Suma red: %d, green: %d, blue: %d\n", sum_red, sum_green, sum_blue);
            sum += games[i].id;
        }
    }

    printf("Suma identyfikatorów możliwych gier: %d\n", sum);

    return 0;
}