#include "FileUtil.h"

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

bool FileUtil::loadGame(std::string fileName, std::shared_ptr<Game> game) {

  std::vector<Player*>* players = new std::vector<Player*>;
  GameBoard* gameBoard = new GameBoard();
  Player* currPlayer;
  LinkedList* tileBag = new LinkedList();

  bool success = true;
  std::string line = "";
  std::fstream inputFile;

  inputFile.open(fileName, std::ios::in);

  if (!inputFile.fail()) {

    while (!inputFile.eof() && success) {

      getline(inputFile, line);
      if (isNameCorrect(line)) {

        Player* player = new Player(line);
        getPlayerData(player, inputFile);
        players->push_back(player);
      }
      else
        success = false;
    }
  }

  if (success) {
    getBoard(gameBoard, inputFile);
  }

  if (success) {
    getline(inputFile, line);
    if (!giveTilesList(line, tileBag))
      success = false;
  }

  if (success) {
    getline(inputFile, line);
    if (isNameCorrect(line))
      currPlayer = new Player(line);
    else
      success = false;
  }

  inputFile.close();

  return success;
}

bool FileUtil::getPlayerData(Player* player, std::fstream& inputFile) {
  std::string line = "";
  bool isCorrect = true;
  while (!inputFile.eof() && isCorrect) {

    getline(inputFile, line);
    try {
      player->setScore(std::stoi(line));
    }
    catch (const std::invalid_argument& e) {
      isCorrect = false;
    }

    if (isCorrect) {
      getline(inputFile, line);
      if (!giveTilesList(line, player->getHand())) {
        isCorrect = false;
      }
    }
  }
  return true;
}


bool FileUtil::giveTilesList(std::string tileList, LinkedList* tilList) {
  bool isCorrect = true;
  std::string tile = "";
  for (int i = 0;i < tileList.size() && isCorrect;i++) {
    if (tileList[i] != ',')
      tile += tileList[i];
    else {
      if (!isTileCorrect(tile))
        isCorrect = false;
      else
        tilList->addTile(new Tile((char)tile[0], (int)tile[1]));

      tile = "";
    }
  }
  return isCorrect;
}

bool FileUtil::isTileCorrect(std::string tile) {
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

bool FileUtil::isNameCorrect(std::string name) {
  bool isCorrect = true;
  for (int index = 0;index < name.size() && isCorrect;index++) {
    if (!('A' <= name[index] && name[index] <= 'Z') ||
      !('a' <= name[index] && name[index] <= 'z')) {
      isCorrect = false;
    }
  }
  return isCorrect;
}

bool FileUtil::getBoard(GameBoard* gameBoard, std::fstream& inputFile) {
  bool success = true;
  std::string line = "";
  getline(inputFile, line);
  int boardSize[2];
  for (int i = 0, j = 0;i < line.size() && success;i++) {
    if (line[i] != ',') {
      boardSize[j] = (int)line[i];
      if (1 > boardSize[j] || boardSize[j] > 26)
        success = false;
      else
        j++;
    }
  }
  if (success) {
    delete gameBoard;
    gameBoard = new GameBoard(boardSize[0], boardSize[1]);
  }

  getline(inputFile, line);
  std::string placetile = "";
  for (int index = 0;index < line.size() && success;index++) {
    if (line[index] != ',' && line[index] != ' ') {
      placetile += line[index];
    }
    else {
      Tile* tile = new Tile((char)placetile[0], (int)placetile[1]);
      if (!gameBoard->placeTile(tile, (char)placetile[3], (int)placetile[4])) {
        success = false;
      }
      delete tile;
      placetile = "";
    }
  }
  return success;
}
