#include <iostream>

using namespace std;

/* some error defines */

#define ERROR       1
#define NO_ERROR    0

/* function to show game help */

int game_help()
{
    cout << "Rock, Paper, Sizzor, Reset, Quit, Help" << endl;
    return NO_ERROR;
}

/* function to be run by program */

int main()
{
    /* default player scores */

    int player1_score = 0;
    int player2_score = 0;

    /* default player choices */

    string player1_choice;
    string player2_choice;

    /* default player2 choices */

    string choices[3] = {"rock", "paper", "sizzor"};

    /* seed the random generator */

    srand(time(0));

    /* show the game help */

    game_help();

    /* start infinite game loop */

    bool running = true;

    while (running)
    {
        /* let player1 choose */

        cout << endl << "PLAYER-1 [" << player1_score << "]--> ";
        cin >> player1_choice;

        /* let player2 choose */

        player2_choice = choices[rand() % 2];
        cout << "PLAYER-2 [" << player2_score << "]--> " << player2_choice << endl << endl;

        /* check if player1 is the winner */

        if (player1_choice == "rock" && player2_choice == "sizzor" || player1_choice == "paper" && player2_choice == "rock" || player1_choice == "sizzor" && player2_choice == "paper") {
            ++player1_score;
            cout << "PLAYER-1 [" << player1_score << "]--> Winner!" << endl;
            cout << "PLAYER-2 [" << player2_score << "]--> Looser!" << endl;

        /* check if player2 is the winner */

        } else if (player2_choice == "rock" && player1_choice == "sizzor" || player2_choice == "paper" && player1_choice == "rock" || player2_choice == "sizzor" && player1_choice == "paper") {
            ++player2_score;
            cout << "PLAYER-2 [" << player2_score << "]--> Winner!" << endl;
            cout << "PLAYER-1 [" << player1_score << "]--> Looser!" << endl;

        /* check if player1 resets the game */

        } else if (player1_choice == "reset") {
            player1_score = 0;
            player2_score = 0;
            continue;

        /* check if player1 asks for help */

        } else if (player1_choice == "reset") {
            game_help();
            continue;

        /* check if player1 quits the game */

        } else if (player1_choice == "quit") {
            running = false;

        /* check if tie between players */

        } else if (player1_choice == player2_choice) {
            cout << "--> Tie!" << endl;

        /* check if invalid choice by player1 */

        } else {
            cout << "--> Invalid choice!" << endl;
        }
    }

    /* return no error at the end */

    return NO_ERROR;
}