#ifndef ASSIGN2_FILE_UTIL_H
#define ASSIGN2_FILE_UTIL_H

#include <memory>
#include <fstream>
#include "Game.h"
<<<<<<< HEAD
#include "Player.h"
#include "LinkedList.h"
=======

// class Game;
>>>>>>> 6456d411df87456745a61ead013d88fac18275f9

class FileUtil {

public:

    // Loads the game details from the given fileName
    // And saves the data into the game class
    bool loadGame(std::string fileName, std::shared_ptr<Game> game);

    // Saves the game's data in the file in the given file name
    void saveGame(std::string fileName, std::shared_ptr<Game> game);

private:
    std::string giveLine(std::fstream& inputFile);
    bool giveTilesList(std::string tileList);
    bool isNameCorrect(std::string name);
    bool isTileCorrect(std::string tile);
    bool getPlayerData(Player* player, std::fstream& inputFile)
};

#endif // ASSIGN2_FILE_UTIL_H