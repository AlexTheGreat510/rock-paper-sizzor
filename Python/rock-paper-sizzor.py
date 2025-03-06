import random

# default player scores

player1_score = 0
player2_score = 0

# default game choices

choices = ["rock", "paper", "sizzor"]

# function to show game help

def game_help():
    print("Rock, Paper, Sizzor, Reset, Quit, Help")

# show the game help

game_help()

# start infinite game loop

running = True

while running:

    # let player1 choose

    player1_choice = str(input(f"\nPLAYER-1 [{player1_score}]--> "))

    # check player1 choice

    match (player1_choice):

        # check if player1 quits the game

        case "quit":
            print("\n--> Thanks for playing!")
            running = False
            continue

        # check if player1 asks for help

        case "help":
            game_help()
            continue

        # check if player1 asks for stats

        case "stats":
            print(f"\nPLAYER-1 [{player1_score}] vs PLAYER-2 [{player2_score}]")
            continue

        # check if player1 resets the game

        case "reset":
            player1_score = 0
            player2_score = 0
            continue

    # let player2 choose

    player2_choice = choices[random.randrange(2)]
    print(f"PLAYER-2 [{player2_score}]--> {player2_choice}\n")

    # check if player1 is the winner

    if (player1_choice == "rock" and player2_choice == "sizzor" or player1_choice == "paper" and player2_choice == "rock" or player1_choice == "sizzor" and player2_choice == "paper"):
        player1_score += 1
        print(f"PLAYER-1 [{player1_score}]--> Winner!")
        print(f"PLAYER-2 [{player2_score}]--> Looser!")

    # check if player2 is the winner

    elif (player2_choice == "rock" and player1_choice == "sizzor" or player2_choice == "paper" and player1_choice == "rock" or player2_choice == "sizzor" and player1_choice == "paper"):
        player2_score += 1
        print(f"PLAYER-1 [{player1_score}]--> Winner!")
        print(f"PLAYER-2 [{player2_score}]--> Looser!")

    # check if tie between players

    elif (player1_choice == player2_choice):
        print("--> Tie!")

    # check if invalid choice by player1

    else:
        print("--> Invalid choice!")
