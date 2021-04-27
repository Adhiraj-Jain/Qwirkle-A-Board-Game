#include "QwirkleGameEngine.h"
#include <iostream>
#include <string>
#include "input-util.h"

QwirkleGameEngine::~QwirkleGameEngine()
{
}

void QwirkleGameEngine::start()
{
    int selection = mainMenu();
    std::cout << std::endl;
    std::cout << std::endl;
    if (selection == NEW_GAME)
        newGame();
    else if (selection == LOAD_GAME)
        loadGame();
    else if (selection == CREDITS)
        credits();
    else if (selection == QUIT)
        quit();
}

int QwirkleGameEngine::mainMenu()
{
    std::cout << "Menu" << std::endl;
    std::cout << "----" << std::endl;

    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << std::endl;
    int selection = mainMenuSelection();

    return selection;
}

int QwirkleGameEngine::mainMenuSelection(){
    return input_util::getOptionUserInput(4);
}

void QwirkleGameEngine::newGame()
{
    std::cout << "Starting a New Game" << std::endl;
    //New Game Functionality - will leave it for those who have do it.
}

void QwirkleGameEngine::loadGame()
{
    //Load Game Functionality - will leave it for those who do it
    std::cout << "Temp Load Game - ALL GOOD" << std::endl; //Delete this when starting to implement loadGame
}

void QwirkleGameEngine::credits()
{
    int team_size = 4;
    std::string team_members[team_size] = {"Jainam Doshi", "Adhiraj Jain", "Ryan Samarakoon", "Muhib Hasan"};
    std::string student_id[team_size] = {"s3825891", "s3821245", "s3844545", "s3850034"};
    std::string email_address[team_size] = {"s3825891@student.rmit.edu.au", "s3821245@student.rmit.edu.au", "s3844545@student.rmit.edu.au", "s3850034@student.rmit.edu.au"};

    std::cout << "----------------------------------------" << std::endl;

    for (int member = 0; member < team_size; member++)
    {
        std::cout << "Name: " << team_members[member] << std::endl;
        std::cout << "Student ID: " << student_id[member] << std::endl;
        std::cout << "Email:  " << email_address[member] << std::endl;
        if (member != team_size - 1)
            std::cout << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
    start(); //call again - watch video demo
}

void QwirkleGameEngine::quit()
{
    std::cout << "Goodbye" << std::endl;
}