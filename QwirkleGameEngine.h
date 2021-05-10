#ifndef ASSIGN2_GAME_ENGINE
#define ASSIGN2_GAME_ENGINE

#define NEW_GAME 1
#define LOAD_GAME 2
#define CREDITS 3
#define QUIT 4

#include "Player.h"
#include "Game.h"
#include "FileUtil.h"
//Proposed Idea: QwirkleGameEngine
//We can conenct the base gameplay methods to this class as well in the future (after further discussion)
//For Instance, Create a constructor that takes in the linked list in the future for instance.

class QwirkleGameEngine {
public:
    //ADD MODIFICATIONS
    ~QwirkleGameEngine();

    //This is like the main functionality for the class.
    void start(); //just make this menu_selection - will see what to do in Tuesday's Meeting.

    //methods pertaining to the main menu.
    int mainMenu();

    void newGame();

    void loadGame();

    void credits();

    static void quit();

private:
    //ADD MODIFICATIONS
};

#endif