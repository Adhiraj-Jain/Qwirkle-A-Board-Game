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

namespace FileUtil {

public:

    // Loads the game details from the given fileName
    // And saves the data into the game class
    bool loadGame(std::string fileName, std::shared_ptr<Game> game);

    // Saves the game's data in the file in the given file name
    void saveGame(std::string fileName, std::shared_ptr<Game> game);

private:
    //Method to get all the data of the player passed.
    bool getPlayerData(Player* player, std::fstream& inputFile);
    //Method to input tiles from the file and store in the linked list passed as params.
    bool giveTilesList(std::string tileList, LinkedList* tilList);
    //Method to check if the current tile is in correct format or not.
    bool isTileCorrect(std::string tile);
    //Method to check if the player name passed as param is in correct format or not.
    bool isNameCorrect(std::string name);
    // Method to get all the data of the Game board including board size and the current state.
    bool getBoard(GameBoard* gameBoard, std::fstream& inputFile);
};

#endif // ASSIGN2_FILE_UTIL_H
