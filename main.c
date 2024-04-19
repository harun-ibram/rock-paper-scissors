#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CHOICE_SIZE 16

typedef struct game {
    int player_c, comp_c;
    int win;
} Game;

int get_choice() {
    int player_c = -1;

    char *player = malloc(CHOICE_SIZE * sizeof(char));
    scanf("%s", player);

    while (player_c == -1) {
        if (!strcmp("Rock", player) || !strcmp("rock", player)) {
            player_c = 0;   
        } else if (!strcmp("Paper", player) || !strcmp("paper", player)) {
            player_c = 1;
        } else if (!strcmp("Scissors", player) || !strcmp("scissors", player)) {
            player_c = 2;
        }
        if (player_c != - 1) {
            free(player);
            return player_c;
        } else {
            printf("Please choose again: ");
            scanf("%s", player);
        }
    }
    free(player);
    return -1;
}

void actualGame(Game* g) {
    if (g->player_c == g->comp_c)
        g->win = 0;
    else {
        g->win = 1;
        if (g->player_c == 0) 
            if (g->comp_c == 1)
                g->win = -1;
        if (g->player_c == 1)
            if (g->comp_c == 2)
                g->win = -1;
        if (g->player_c == 2)
            if (g->comp_c == 0)
                g->win = -1;
    }
    switch (g->win) {
        case -1:
            printf("YOU LOST!\n");
            break;
        case 0:
            printf("DRAW!\n");
            break;
        case 1:
            printf("YOU WON!\n");
            break;
    }
}

void writeChoice (int this, char *here, size_t thisMuch) {
    switch(this) {
        case 0:
            snprintf(here, thisMuch ,"Rock");
            break;
        case 1:
            snprintf(here, thisMuch, "Paper");
            break;
        case 2:
            snprintf(here, thisMuch, "Scissors");
            break;
    }
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    printf("Let's play 'Rock, Paper, Scissors'!\nMake your choice: ");
    Game g;
    g.comp_c = rand() % 3;  // Rock = 0, Paper = 1, Scissors = 2
    g.player_c = get_choice();
    g.win = 0;
    char *player = calloc(CHOICE_SIZE, 1);
    char *comp = calloc(CHOICE_SIZE, 1);
    writeChoice(g.player_c, player, CHOICE_SIZE);
    writeChoice(g.comp_c, comp, CHOICE_SIZE);
    printf("Player: %s\nComputer: %s\n", player, comp); 
    actualGame(&g);
    free(player);
    free(comp);
    return 0;
}
