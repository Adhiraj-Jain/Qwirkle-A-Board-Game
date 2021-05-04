#ifndef ASSIGN2_FILE_UTIL_H
#define ASSIGN2_FILE_UTIL_H

#include <memory>
#include <fstream>
#include "Game.h"
#include "Player.h"
#include "LinkedList.h"

class file_util {

public:

    bool loadGame(std::string fileName, std::shared_ptr<Game> game);
    bool saveGame(std::string fileName, std::unique_ptr<Game> game);

private:
    std::string giveLine(std::fstream& inputFile);
    bool giveTilesList(std::string tileList);
    bool isNameCorrect(std::string name);
    bool isTileCorrect(std::string tile);
    bool getPlayerData(Player* player, std::fstream& inputFile)
};

#endif // ASSIGN2_FILE_UTIL_H