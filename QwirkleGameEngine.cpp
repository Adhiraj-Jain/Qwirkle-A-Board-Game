#include "QwirkleGameEngine.h"
#include <iostream>
#include <string>
#include "input_util.h"
#include "FileUtil.h"
#include "Game.h"

#define TEAM_SIZE 4

QwirkleGameEngine::~QwirkleGameEngine() = default;

void QwirkleGameEngine::start() {
    int selection = 0;
    std::cout << std::endl;
    std::cout << std::endl;
    do {
        selection = mainMenu();
        if (selection == NEW_GAME)
            newGame();
        else if (selection == LOAD_GAME)
            loadGame();
        else if (selection == CREDITS)
            credits();
        else if (selection == QUIT)
            quit();
    } while (selection != CREDITS && selection != QUIT);
}

int QwirkleGameEngine::mainMenu() {
    std::cout << "Menu" << std::endl;
    std::cout << "----" << std::endl;

    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << std::endl;
    int selection = input_util::getOptionUserInput(4);

    return selection;
}

void QwirkleGameEngine::newGame() {
    std::cout << "Starting a New Game" << std::endl;
    //New Game Functionality - will leave it for those who have do it.
    //Make Players
    std::cout << std::endl;
    std::vector<std::shared_ptr<Player>> players;
    int playerSize = 2;

    for (int player = 0; player < playerSize; player++) {
        std::cout << "Enter a name for player " << player << "uppercase characters only" << std::endl;
        std::string creatingPlayerInput = input_util::getStringInput(std::regex("^[A-Z]+$"));
        std::shared_ptr<Player> creatingPlayer = std::make_shared<Player>(creatingPlayerInput);
        players.push_back(creatingPlayer);
        std::cout << std::endl;
    }
    std::cout << "Let's Play" << std::endl;
    std::cout<<std::endl;
    //Initialize the game (calling the first constructor of the game) - initialize method.
    std::shared_ptr<Game> newGame = std::make_shared<Game>(players);
    newGame->initiation();
    newGame->start();
}

void QwirkleGameEngine::loadGame() {
    // FileUtil* fileUtil = new FileUtil();
    // std::shared_ptr<Game> game = std::make_shared<Game>(nullptr);
    // fileUtil->loadGame("inputFile.txt", game);
    //Load Game Functionality - will leave it for those who do it
    std::cout << "Temp Load Game - ALL GOOD" << std::endl; //Delete this when starting to implement loadGame
}

void QwirkleGameEngine::credits() {
    std::string team_members[TEAM_SIZE] = {"Jainam Doshi", "Adhiraj Jain", "Ryan Samarakoon", "Muhib Hasan"};
    std::string student_id[TEAM_SIZE] = {"s3825891", "s3821245", "s3844545", "s3850034"};
    std::string email_address[TEAM_SIZE] = {"s3825891@student.rmit.edu.au", "s3821245@student.rmit.edu.au",
                                            "s3844545@student.rmit.edu.au", "s3850034@student.rmit.edu.au"};

    std::cout << "----------------------------------------" << std::endl;

    for (int member = 0; member < TEAM_SIZE; member++) {
        std::cout << "Name: " << team_members[member] << std::endl;
        std::cout << "Student ID: " << student_id[member] << std::endl;
        std::cout << "Email:  " << email_address[member] << std::endl;
        if (member != TEAM_SIZE - 1)
            std::cout << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
}

void QwirkleGameEngine::quit() {
    std::cout << "Goodbye" << std::endl;
}