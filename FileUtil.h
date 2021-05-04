#ifndef ASSIGN2_FILE_UTIL_H
#define ASSIGN2_FILE_UTIL_H

#include <memory>
#include <fstream>
#include "Game.h"

// class Game;

class FileUtil {

public:

    // Loads the game details from the given fileName
    // And saves the data into the game class
    bool loadGame(std::string fileName, std::shared_ptr<Game> game);

    // Saves the game's data in the file in the given file name
    void saveGame(std::string fileName, std::shared_ptr<Game> game);

private:

};

#endif // ASSIGN2_FILE_UTIL_H