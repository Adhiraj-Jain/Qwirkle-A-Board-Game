#ifndef ASSIGN2_FILE_UTIL_H
#define ASSIGN2_FILE_UTIL_H

#include <memory>
#include <fstream>

class Game;

class FileUtil {

public:

    bool loadGame(std::string fileName, std::shared_ptr<Game> game);
    bool saveGame(std::string fileName, std::shared_ptr<Game> game);

private:

};

#endif // ASSIGN2_FILE_UTIL_H