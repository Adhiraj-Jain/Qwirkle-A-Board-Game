#include "FileUtil.h"
#include <fstream>

bool FileUtil::loadGame(std::string fileName, std::shared_ptr<Game> game) {

  return true;
}

void FileUtil::saveGame(std::string fileName, std::shared_ptr<Game> game) {

  // Finds and opens the file for writing
  std::fstream outfile;
  outfile.open(fileName, std::ios::out);

  // Gets the game's data as a string
  std::string gameString = game->toString();

  // Writing character by character into the file
  for (unsigned int i = 0; i < gameString.size(); i++) {
    outfile.put(gameString.at(i));
  }

  // Closing the file
  outfile.close();
}
