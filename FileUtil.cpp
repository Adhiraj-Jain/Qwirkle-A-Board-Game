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

  // Counter for all players.
  std::vector<Player*>* players = new std::vector<Player*>;
  //Counter for current state of Board
  GameBoard* gameBoard = new GameBoard();
  //Counter for current Player
  Player* currPlayer;
  // Counter for current tileBag.
  LinkedList* tileBag = new LinkedList();
  // Counter to check if the loading is a success or not
  bool success = true;
  //To get line from the input file
  std::string line = "";
  // fstream object to get data from text file.
  std::fstream inputFile;
  //Opening text file in read only mode.
  inputFile.open(fileName, std::ios::in);
  //Checking for file existence
  if (!inputFile.fail()) {
    //Loop till it reaches end of file and loop while the current state of loading the file is a success.
    while (!inputFile.eof() && success) {
      //Get a line from text file
      getline(inputFile, line);
      //Check if the name is in ASCII text means contains all letters.
      if (isNameCorrect(line)) {
        //Create a player object
        Player* player = new Player(line);
        //Calling getPlayerData() to get the data of this player.
        getPlayerData(player, inputFile);
        //Pushing this player into vector array of players.
        players->push_back(player);
      }
      else
        //If the name is not in ASCII text.
        success = false;
    }
  }

  //To get the Game Board data.
  //Only proceeds further if the previous data input was correct
  if (success) {
    //Call to get the board size and its current state and check if it was successfull or not
    if (!getBoard(gameBoard, inputFile))
      success = false;
  }
  // To store all the tiles in the tileBag.
  if (success) {
    getline(inputFile, line);
    //Call to get all current tiles in tileBag and check if it was successfull or not.
    if (!giveTilesList(line, tileBag))
      success = false;
  }

  //To get the current player
  if (success) {
    getline(inputFile, line);
    if (isNameCorrect(line))
      currPlayer = new Player(line);
    else
      success = false;
  }
  //Close the file.
  inputFile.close();
  //If the inputs from file was successfull
  if (success) {
    // Intialize the game with the new params.
    game = std::make_shared<Game>(players, currPlayer, gameBoard, tileBag);
  }
  //Return
  return success;
}


bool FileUtil::getPlayerData(Player* player, std::fstream& inputFile) {

  std::string line = "";
  //To keep the current state of input
  bool isCorrect = true;
  //Loop till eof or the input state is true
  while (!inputFile.eof() && isCorrect) {

    getline(inputFile, line);
    //Try converting score in string format to integer format and catch if it throws any exception
    try {
      //Set the score
      player->setScore(std::stoi(line));
    }
    catch (const std::invalid_argument& e) {
      //If the input string line from text file does not contain all digits.
      isCorrect = false;
    }
    //Proceed further only when earlier input was correct.
    if (isCorrect) {
      getline(inputFile, line);
      //Get hand of tiles of the player and check if it was a success or not.
      if (!giveTilesList(line, player->getHand())) {
        isCorrect = false;
      }
    }
  }
  return isCorrect;
}


bool FileUtil::giveTilesList(std::string tileList, LinkedList* tileLL) {
  bool isCorrect = true;
  std::string tile = "";
  //Traverse over the line to find all the tiles.
  for (unsigned int i = 0;i < tileList.size() && isCorrect;i++) {
    //If the current char is not a comma.
    if (tileList[i] != ',')
      //Add the char into string tile.
      tile += tileList[i];
    else {
      //If the current char is a comma.
      //Call to check if the current tile is in correct format or not.
      if (!isTileCorrect(tile))
        isCorrect = false;
      else
        //If the tile is in correct format then store it in the tileLL
        tileLL->addTile(new Tile((char)tile[0], (int)tile[1]));
      //Clear the current tile.
      tile = "";
    }
  }
  //Return
  return isCorrect;
}


bool FileUtil::isTileCorrect(std::string tile) {
  bool isCorrect = false;
  //Array of char colours
  char colors[] = { RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE };
  // check if the shape of tile is in correct range or not.
  if (1 <= (int)tile[1] && ((int)tile[1]) <= 7) {
    //Looping over the colours array till it founds a correct match or till the end of array.
    for (int index = 0; index < 6 && !isCorrect;index++) {
      //If the colour matches
      if (colors[index] == (char)tile[0])
        isCorrect = true;
    }
  }
  //Return
  return isCorrect;
}


// TODO replace with regex
bool FileUtil::isNameCorrect(std::string name) {
  bool isCorrect = true;
  //loop over each of letter of the string
  for (unsigned int index = 0;index < name.size() && isCorrect;index++) {
    //Check if the current letter is in correct range or not.
    if (!('A' <= name[index] && name[index] <= 'Z') ||
      !('a' <= name[index] && name[index] <= 'z')) {
      isCorrect = false;
    }
  }
  //Return
  return isCorrect;
}

bool FileUtil::getBoard(GameBoard* gameBoard, std::fstream& inputFile) {
  bool success = true;
  std::string line = "";
  getline(inputFile, line);
  //Integer array to store dimensions of the game board.
  int boardSize[2];
  //Loop over the line got through input stream.
  for (unsigned int i = 0, j = 0;i < line.size() && success;i++) {
    if (line[i] != ',') {
      //Store the dimension into integer array
      boardSize[j] = (int)line[i];
      // Check if the dimension falls within the correct range or not.
      if (1 > boardSize[j] || boardSize[j] > 26)
        //If falls outside the range.
        success = false;
      else
        j++;
    }
  }

  //If earlier input was a success
  if (success) {
    //Delete the gameboard to which it was pointing to.
    delete gameBoard;
    //initialising a new game board object.
    gameBoard = new GameBoard(boardSize[0], boardSize[1]);
  }
  // Take input for the current state of the board i.e., currently placed tiles on the board.
  getline(inputFile, line);
  //A Const to check to for the size of each placetile
  const int size = 5;
  std::string placetile = "";
  //Loop till end of line or the input format till that point is correct.
  for (unsigned int index = 0;index < line.size() && success;index++) {
    //Check for comma and a white space.
    if (line[index] != ',' && line[index] != ' ') {
      //If not then add the character in the string.
      placetile += line[index];
    }
    //Check if it is a comma means end of string of one placed tile data and the length of tile is 5 eg. Y5@A1
    else if (line[index] == ',' && placetile.size() == size) {
      //if the tile input is completed.
      //Create a new tile.
      Tile* tile = new Tile((char)placetile[0], (int)placetile[1]);
      //Place the tile in the game board with the given row and col.
      if (!gameBoard->placeTile(tile, (char)placetile[3], (int)placetile[4])) {
        //If placing a tile was not a success.
        success = false;
      }
      //delete the tile.
      delete tile;
      //Clear the data for next tile.
      placetile = "";
    }
    //If it was a comma but the length of tile was not in format.
    else if (line[index] == ',' && placetile.size() != size)
      success = false;
  }
  //Return
  return success;
}
