#include <iostream>

using namespace std;

/* some error defines */

#define ERROR       1
#define NO_ERROR    0

/* function to show game help */

int game_help()
{
    cout << "Rock, Paper, Sizzor, Stats, Reset, Quit, Help" << endl;
    return NO_ERROR;
}

/* function to be run by program */

int main()
{
    /* increment run count */

    int run_count = 0;

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
        /* increment run count */

        ++run_count;

        /* let player1 choose */

        cout << endl << "(" << run_count << ") PLAYER-1 [" << player1_score << "]--> ";
        cin >> player1_choice;

        /* check if player1 asks for stats */

        if (player1_choice == "stats") {
            cout << endl << "(" << run_count << ") PLAYER-1 [" << player1_score << "] vs PLAYER-2 [" << player2_score << "]" << endl;
            continue;

        /* check if player1 resets the game */

        } else if (player1_choice == "reset") {
            run_count = 0;
            player1_score = 0;
            player2_score = 0;
            continue;

        /* check if player1 asks for help */

        } else if (player1_choice == "help") {
            game_help();
            continue;

        /* check if player1 quits the game */

        } else if (player1_choice == "quit") {
            cout << endl << "--> Thanks for playing!" << endl;
            running = false;
            continue;
        }

        /* let player2 choose */

        player2_choice = choices[rand() % 2];
        cout << "(" << run_count << ") PLAYER-2 [" << player2_score << "]--> " << player2_choice << endl << endl;

        /* check if player1 is the winner */

        if (player1_choice == "rock" && player2_choice == "sizzor" || player1_choice == "paper" && player2_choice == "rock" || player1_choice == "sizzor" && player2_choice == "paper") {
            ++player1_score;
            cout << "(" << run_count << ") PLAYER-1 [" << player1_score << "]--> Winner!" << endl;
            cout << "(" << run_count << ") PLAYER-2 [" << player2_score << "]--> Looser!" << endl;

        /* check if player2 is the winner */

        } else if (player2_choice == "rock" && player1_choice == "sizzor" || player2_choice == "paper" && player1_choice == "rock" || player2_choice == "sizzor" && player1_choice == "paper") {
            ++player2_score;
            cout << "(" << run_count << ") PLAYER-2 [" << player2_score << "]--> Winner!" << endl;
            cout << "(" << run_count << ") PLAYER-1 [" << player1_score << "]--> Looser!" << endl;

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
