#ifndef ASSIGN2_FILE_UTIL_H
#define ASSIGN2_FILE_UTIL_H

#include <memory>
#include <fstream>
#include "Game.h"
#include "Player.h"
#include "LinkedList.h"
#include "TileCodes.h"
#include "GameBoard.h"
#include "Tile.h"

class FileUtil {

public:

    // Loads the game details from the given fileName
    // And saves the data into the game class
    bool loadGame(std::string fileName, std::shared_ptr<Game> game);

    // Saves the game's data in the file in the given file name
    void saveGame(std::string fileName, std::shared_ptr<Game> game);

private:
    std::string giveLine(std::fstream& inputFile);
    bool giveTilesList(std::string tileList, LinkedList* tilList);
    bool isNameCorrect(std::string name);
    bool isTileCorrect(std::string tile);
    bool getPlayerData(Player* player, std::fstream& inputFile);
    bool getBoard(GameBoard* gameBoard, std::fstream& inputFile);
};

#endif // ASSIGN2_FILE_UTIL_H