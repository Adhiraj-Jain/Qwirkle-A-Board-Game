#ifndef ASSIGN2_GAME_ENGINE
#define ASSIGN2_GAME_ENGINE


#include "constants.h"
#include "Player.h"
#include "Game.h"
#include "FileUtil.h"
#include <map>
//Proposed Idea: QwirkleGameEngine
//We can conenct the base gameplay methods to this class as well in the future 


class QwirkleGameEngine {
public:
    //Contructor for random seed
    explicit QwirkleGameEngine(unsigned int seed);

    //Constructor
    QwirkleGameEngine();

    //Destructor
    ~QwirkleGameEngine();

    //This is like the main functionality for the class.
    void start();

    //methods pertaining to the main menu are called in this function
    int mainMenu();

    //New game functionality
    void newGame();

    //Load game functionality
    void loadGame();

    //Credits functionality
    void credits();

    //Quit functionality
    static void quit();

private:

    //Class Variable
    unsigned int seed = 0;

    void setDefaultEnhancements();

    std::map<string, bool> enhancements;

    void changeEnhancement(string enhancement);
};

#endif