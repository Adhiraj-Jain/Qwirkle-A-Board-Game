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
#include <regex>
#include "typedefs.h"

class FileUtil {

public:

    // Loads the game details from the given fileName
    // Returns a game instance if read successfully
    // Returns a nullpte if read unsuccessfully
    static std::shared_ptr<Game> loadGame(string fileName);

    // Saves the game's data in the file in the given file name
    static void saveGame(string fileName, Game* game);

private:
    //Method to get all the data of the player passed.
    static bool getPlayerData(SharedPlayer player, std::fstream& inputFile);

    //Method to input tiles from the file and store in the linked list passed as params.
    static std::shared_ptr<LinkedList> giveTilesList(string tileList);

    //Method to check if the current tile is in correct format or not.
    static bool isTileCorrect(string tile);

    //Method to check if the player name passed as param is in correct format or not.
    static bool isNameCorrect(string name);

    // Method to get all the data of the Game board including board size and the current state.
    static std::shared_ptr<GameBoard> getBoard(std::fstream& inputFile);
};

#endif // ASSIGN2_FILE_UTIL_H
