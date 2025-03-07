#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* some error defines */

#define ERROR       true
#define NO_ERROR    false

/* function to show the game help */

bool game_help()
{
    puts("Rock, Paper, Sizzor, Stats, Reset, Quit, Help");
    return NO_ERROR;
}

/* function to be run by program */

bool main()
{
    /* default run count */

    int run_count = 0;

    /* default player scores */

    int player1_score = 0;
    int player2_score = 0;

    /* default player choices */

    char player1_choice[10];
    char *player2_choice;

    /* default game choices */

    char *choices[] = {"rock", "paper", "sizzor"};

    /* seed the random generator */

    srand(time(NULL));

    /* show the game help */

    game_help();

    /* start infinite game loop */

    bool running = true;

    while (running)
    {
        /* increment run count */

        ++run_count;

        /* let player1 choose */

        printf("\n(%d) PLAYER-1 [%d]--> ", run_count, player1_score);
        scanf("%s", &player1_choice);

        /* check if player1 asks for stats */

        if (!strcmp(player1_choice, "stats")) {
            printf("\n(%d) PLAYER-1 [%d] vs PLAYER-2 [%d]\n", run_count, player1_score, player2_score);
            continue;

        /* check if player1 resets the game */

        } else if (!strcmp(player1_choice, "reset")) {
            run_count = 0;
            player1_score = 0;
            player2_score = 0;
            continue;

        /* check if player1 quits the game */

        } else if (!strcmp(player1_choice, "quit")) {
            puts("\n--> Thanks for playing!");
            running = false;
            continue;

        /* check if player1 asks for help */

        } else if (!strcmp(player1_choice, "help")) {
            game_help();
            continue;
        }

        /* let player2 choose */

        player2_choice = choices[rand() % 3];
        printf("(%d) PLAYER-2 [%d]--> %s\n\n", run_count, player2_score, player2_choice);

        /* check if player1 is the winner */

        if (!strcmp(player1_choice, "rock") && !strcmp(player2_choice, "sizzor") || !strcmp(player1_choice, "paper") && !strcmp(player2_choice, "rock") || !strcmp(player1_choice, "sizzor") && !strcmp(player2_choice, "paper")) {
            ++player1_score;
            printf("(%d) PLAYER-1 [%d]--> Winner!\n", run_count, player1_score);
            printf("(%d) PLAYER-2 [%d]--> Looser!\n", run_count, player2_score);

        /* check if player2 is the winner */

        } else if (!strcmp(player2_choice, "rock") && !strcmp(player1_choice, "sizzor") || !strcmp(player2_choice, "paper") && !strcmp(player1_choice, "rock") || !strcmp(player2_choice, "sizzor") && !strcmp(player1_choice, "paper")) {
            ++player2_score;
            printf("(%d) PLAYER-2 [%d]--> Winner!\n", run_count, player2_score);
            printf("(%d) PLAYER-1 [%d]--> Looser!\n", run_count, player1_score);

        /* check if tie between players */

        } else if (!strcmp(player1_choice, player2_choice)) {
            puts("--> Tie!");

        /* check if invalid choice by player1 */

        } else {
            puts("--> Invalid choice!");
        }
    }

    /* return no error at the end */

    return NO_ERROR;
}
