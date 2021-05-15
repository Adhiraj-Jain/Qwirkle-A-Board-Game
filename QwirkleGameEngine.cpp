#include "QwirkleGameEngine.h"
#include <iostream>
#include <string>

QwirkleGameEngine::~QwirkleGameEngine() = default;

QwirkleGameEngine::QwirkleGameEngine(): QwirkleGameEngine(std::chrono::system_clock::now().time_since_epoch().count()) {}

QwirkleGameEngine::QwirkleGameEngine(unsigned int seed) {
    this->seed = seed;
}

void QwirkleGameEngine::start() {
    int selection = 0;
    std::cout << std::endl;
    std::cout << std::endl;
    do {
        selection = mainMenu();
        if (selection == NEW_GAME) {
            newGame();
        }
        else if (selection == LOAD_GAME) {
            loadGame();
        }
        else if (selection == CREDITS) {
            credits();
        }
        else if (selection == QUIT) {
            quit();
        }
    } while (selection != QUIT);
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
    std::vector<SharedPlayer> players;
    int playerSize = 2;

    for (int player = 0; player < playerSize; player++) {
        std::cout << "Enter a name for player " << player+1 << " (uppercase characters only)" << std::endl;
        string creatingPlayerInput = input_util::getStringInput(std::regex("^[A-Z]+$"));
        SharedPlayer creatingPlayer = std::make_shared<Player>(creatingPlayerInput);
        players.push_back(creatingPlayer);
        std::cout << std::endl;
    }
    std::cout << "Let's Play" << std::endl << std::endl;
    //Initialize the game (calling the first constructor of the game) - initialize method.
    std::shared_ptr<Game> newGame = std::make_shared<Game>(players);
    newGame->initiation(seed);
    newGame->start();
}

void QwirkleGameEngine::loadGame() {
    std::cout << "Enter file path:" << std::endl;
    string fileInput = input_util::getStringInput(std::regex(".+"));
    std::shared_ptr<Game> newGame;
    newGame = FileUtil::loadGame(fileInput);
    if (newGame != nullptr) {
        std::cout << "Qwirkle game successfully loaded" << std::endl;
        newGame->start();
    } else {
        std::cout << "Invalid Game" << std::endl;
    }
}

void QwirkleGameEngine::credits() {
    string team_members[TEAM_SIZE] = {"Jainam Doshi", "Adhiraj Jain", "Ryan Samarakoon", "Muhib Hasan"};
    string student_id[TEAM_SIZE] = {"s3825891", "s3821245", "s3844545", "s3850034"};
    string email_address[TEAM_SIZE] = {"s3825891@student.rmit.edu.au", "s3821245@student.rmit.edu.au",
                                       "s3844545@student.rmit.edu.au", "s3850034@student.rmit.edu.au"};

    std::cout << "----------------------------------------" << std::endl;

    for (int member = 0; member < TEAM_SIZE; member++) {
        std::cout << "Name: " << team_members[member] << std::endl;
        std::cout << "Student ID: " << student_id[member] << std::endl;
        std::cout << "Email:  " << email_address[member] << std::endl;
        if (member != TEAM_SIZE - 1) {
            std::cout << std::endl;
        }
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
}

void QwirkleGameEngine::quit() {
    std::cout << "Goodbye" << std::endl;
    exit(0);
}
