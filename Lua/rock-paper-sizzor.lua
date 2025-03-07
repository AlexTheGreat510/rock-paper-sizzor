-- default run count

local run_count = 0

-- default player scores

local player1_score = 0
local player2_score = 0

-- default player choices

local player1_choice
local player2_choice

-- default game choices

local choices = {"rock", "paper", "sizzor"}

-- function to show game help

local function game_help()
    print("Rock, Paper, Sizzor, Stats, Reset, Quit, Help")
end

-- show the game help

game_help()

-- start infinite game loop

local running = true

while running do

    -- increment run count
    
    run_count = run_count + 1

    -- let player1 choose

    io.write(string.format("\n(%d) PLAYER-1 [%d]--> ", run_count, player1_score))
    player1_choice = io.read()

    -- check if player1 resets the game

    if player1_choice == "reset" then
        run_count = 0
        player1_score = 0
        player2_score = 0
        goto continue

    -- check if player1 asks for stats

    elseif player1_choice == "stats" then
        print(string.format("(%d) PLAYER-1 [%d] vs PLAYER-2 [%d]", run_count, player1_score, player2_score))

    -- check if player1 asks for help

    elseif player1_choice == "help" then
        game_help()
        goto continue

    -- check if player1 quits the game

    elseif player1_choice == "quit" then
        print("\n--> Thanks for playing!")
        running = false
        goto continue
    end

    -- let player2 choose

    player2_choice = choices[math.random(3)]
    print(string.format("(%d) PLAYER-2 [%d]--> %s\n", run_count, player2_score, player2_choice))

    -- check if player1 is the winner

    if player1_choice == "rock" and player2_choice == "sizzor" or player1_choice == "paper" and player2_choice == "rock" or player1_choice == "sizzor" and player2_choice == "paper" then
        player1_score = player1_score + 1
        print(string.format("(%d) PLAYER-1 [%d]--> Winner!", run_count, player1_score))
        print(string.format("(%d) PLAYER-2 [%d]--> Looser!", run_count, player2_score))

    -- check if player2 is the winner

    elseif player2_choice == "rock" and player1_choice == "sizzor" or player2_choice == "paper" and player1_choice == "rock" or player2_choice == "sizzor" and player1_choice == "paper" then
        player2_score = player2_score + 1
        print(string.format("(%d) PLAYER-2 [%d]--> Winner!", run_count, player2_score))
        print(string.format("(%d) PLAYER-1 [%d]--> Looser!", run_count, player1_score))

    -- check if tie between players

    elseif player1_choice == player2_choice then
        print("--> Tie!")

    -- check if invalid choice by player1

    else
        print("--> Invalid choice!")
    end

    ::continue::
end
