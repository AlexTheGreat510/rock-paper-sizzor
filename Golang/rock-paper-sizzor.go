package main

/* import modules */

import (
    "fmt"
    "math/rand"
)

/* function to show game help */

func gameHelp() {
    fmt.Println("Rock, Paper, Sizzor, Stats, Reset, Quit, Help")
}

/* function to be run by program */

func main() {
    
    /* default run count */

    var runCount int = 0

    /* default player scores */

    var player1Score int = 0
    var player2Score int = 0

    /* default player choices */

    var player1Choice string
    var player2Choice string

    /* default game choices */

    var choices = [3]string{"rock", "paper", "sizzor"}

    /* show the game help */

    gameHelp()

    /* start infinite game loop */

    var running bool = true

    for running {
        
        /* increment run count */

        runCount++;

        /* let player1 choose */

        fmt.Printf("\n(%d) PLAYER-1 [%d] --> ", runCount, player1Score)
        fmt.Scanln(&player1Choice)

        /* check player1 choices */

        switch player1Choice {

            /* check if player1 resets the game */

            case "reset":
                runCount = 0
                player1Score = 0
                player2Score = 0
                continue

            /* check if player1 asks for help */

            case "help":
                gameHelp()
                continue

            /* check if player1 asks for stats */

            case "stats":
                fmt.Printf("\n(%d) PLAYER-1 [%d] vs PLAYER-2 [%d]\n", runCount, player1Score, player2Score)
                continue

            /* check if player1 quits the game */

            case "quit":
                fmt.Println("\n--> Thanks for playing!");
                running = false
                continue
        }

        /* let player2 choose */

        player2Choice = choices[rand.Intn(3)]
        fmt.Printf("(%d) PLAYER-2 [%d] --> %s\n\n", runCount, player2Score, player2Choice)

        /* check if player1 is the winner */

        if (player1Choice == "rock" && player2Choice == "sizzor" || player1Choice =="paper" && player2Choice == "rock" || player1Choice == "sizzor" && player2Choice == "paper") {
            player1Score++;
            fmt.Printf("(%d) PLAYER-1 [%d] --> Winner!\n", runCount, player1Score)
            fmt.Printf("(%d) PLAYER-2 [%d] --> Looser!\n", runCount, player2Score)

        /* check if player2 is the winner */

        } else if (player2Choice == "rock" && player1Choice == "sizzor" || player2Choice =="paper" && player1Choice == "rock" || player2Choice == "sizzor" && player1Choice == "paper") {
            player2Score++;
            fmt.Printf("(%d) PLAYER-2 [%d] --> Winner!\n", runCount, player2Score)
            fmt.Printf("(%d) PLAYER-1 [%d] --> Looser!\n", runCount, player1Score)

        /* check if tie between players */

        } else if (player1Choice == player2Choice) {
            fmt.Println("--> Tie!")

        /* check if invalid choice by player1 */

        } else {
            fmt.Println("--> Invalid choice!")
        }
    }
}
