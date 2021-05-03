#ifndef ASSIGN2_FILE_UTIL_H
#define ASSIGN2_FILE_UTIL_H

#include <memory>

class Game;

class file_util {

public:

    bool loadGame(std::string fileName, std::unique_ptr<Game> game);
    bool saveGame(std::string fileName, std::unique_ptr<Game> game);

private:

};

#endif // ASSIGN2_FILE_UTIL_H