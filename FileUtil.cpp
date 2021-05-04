#include "FileUtil.h"
<<<<<<< HEAD

#include <iostream>

#include "TileCodes.h"

bool file_util::loadGame(std::string fileName, std::shared_ptr<Game> game) {

  std::shared_ptr<Game> tempGame = std::make_shared<Game>();

  bool success = false;
  std::string line = "";
  std::fstream inputFile;

  inputFile.open(fileName, std::ios::in);

  if (!inputFile.fail()) {

    while (!inputFile.eof()) {

      getline(inputFile, line);
      if (isNameCorrect(line)) {
        Player* player = new Player(line);
        getPlayerData(player);
        game->getPlayers().push_back(player);
      }

    }
  }
  inputFile.close();

  return success;
}

bool file_util::getPlayerData(Player* player, std::fstream& inputFile) {
  std::string line = "";

  while (!inputFile.eof()) {

    getline(inputFile, line);
    if (isNameCorrect(line)) {
      getPlayerData(player);
      game->getPlayers().push_back(player);
    }

  }
  return true;
}

// std::string file_util::giveLine(std::fstream& inputFile) {
//   std::string newLine = "";
//   getline(inputFile, newLine);
//   return newLine;
// }

bool file_util::giveTilesList(std::string tileList) {
  bool isCorrect = true;
  LinkedList* linkedList = new LinkedList();
  std::string tile = "";
  for (int i = 0;i < tileList.size() && isCorrect;i++) {
    if (tileList[i] != ',')
      tile += tileList[i];
    else {
      if (!isTileCorrect)
        isCorrect = false;
      else
        linkedList->addTile(new Tile((char)tile[0], (int)tile[1]));

      tile = "";
    }
  }
}

bool file_util::isTileCorrect(std::string tile) {
  bool isCorrect = false;
  char colors[] = { RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE };
  if (1 <= (int)tile[1] && ((int)tile[1]) <= 7) {
    for (int index = 0; index < 6 && !isCorrect;index++) {
      if (colors[index] == (char)tile[0])
        isCorrect = true;
    }
  }
  return isCorrect;
}

bool file_util::isNameCorrect(std::string name) {
  bool isCorrect = true;
  for (int index = 0;index < name.size() && isCorrect;index++) {
    if (!('A' <= name[index] && name[index] <= 'Z') ||
      !('a' <= name[index] && name[index] <= 'z')) {
      isCorrect = false;
    }
  }
  return isCorrect;
}
=======
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
>>>>>>> 6456d411df87456745a61ead013d88fac18275f9
