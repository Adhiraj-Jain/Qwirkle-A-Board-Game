#include "FileUtil.h"

void FileUtil::saveGame(const string& fileName, Game* game) {

    // Finds and opens the file for writing
    std::fstream outfile;
    outfile.open(fileName, std::ios::out);

    // Gets the game's data as a string
    string gameString = game->toString();

    // Writing character by character into the file
    for (char i : gameString) {
        outfile.put(i);
    }

    outfile.close();
}

std::shared_ptr<Game> FileUtil::loadGame(const string& fileName) {

    // Counter for all players.
    SharedVector<SharedPlayer> players = std::make_shared<std::vector<SharedPlayer>>();

    //Counter for current state of Board
    std::shared_ptr<GameBoard> gameBoard;
    //Counter for current Player
    SharedPlayer currPlayer;
    // Counter for current tileBag.
    std::shared_ptr<LinkedList> tileBag;

    // Counter to check if the loading is a success or not
    bool success = true;
    //To get line from the input file
    string line = "";
    // fstream object to get data from text file.
    std::fstream inputFile;
    //Opening text file in read only mode.
    inputFile.open(fileName, std::ios::in);
    //Checking for file existence
    if (!inputFile.fail()) {
        //Loop till it reaches end of file and loop while the current state of loading the file is a success.
        while (!inputFile.eof() && success && players->size() < MAX_PLAYERS) {
            //Get a line from text file
            input_util::getline(inputFile, line);
            //Check if the name is in ASCII text means contains all letters.
            if (isNameCorrect(line)) {
                SharedPlayer player = std::make_shared<Player>(line);
                //Calling getPlayerData() to get the data of this player.
                if (!getPlayerData(player, inputFile)) {
                    success = false;
                }
                else {
                    //Pushing this player into vector array of players.
                    players->push_back(player);
                }
            }
            else {
                //If the name is not in ASCII text.
                success = false;
            }
        }
        //To get the Game Board data.
        //Only proceeds further if the previous data input was correct
        if (success) {
            //Call to get the board size and its current state and check if it was successful or not
            gameBoard = getBoard(inputFile);
            if (gameBoard == nullptr) {
                success = false;
            }
        }
        // To store all the tiles in the tileBag.
        if (success) {
            input_util::getline(inputFile, line);
            //Call to get all current tiles in tileBag and check if it was successful or not.
            if (line.size() > 0) {
                tileBag = giveTilesList(line);
                if (tileBag == nullptr) {
                    success = false;
                }
            }
            else {
                //If the input line is empty means no tile present in tilebag.
                tileBag = std::make_shared<LinkedList>();
            }
        }

        //To get the current player
        if (success) {
            input_util::getline(inputFile, line);
            if (isNameCorrect(line)) {
                for (SharedPlayer& player : *players) {
                    if (player->getName() == line) {
                        currPlayer = player;
                    }
                }
            }
            else {
                success = false;
            }
        }
    }
    else {
        success = false;
    }
    //Close the file.
    inputFile.close();

    //If the inputs from file was successful
    std::shared_ptr<Game> game = nullptr;
    if (success) {
        // Initialize the game with the new params.
        game = std::make_shared<Game>(players, currPlayer, gameBoard, tileBag);
    }
    //Return
    return game;
}


bool FileUtil::getPlayerData(const SharedPlayer& player, std::fstream& inputFile) {

    string line = "";
    //To keep the current state of input
    bool isCorrect = true;
    //Loop till eof or the input state is true

    input_util::getline(inputFile, line);
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
        input_util::getline(inputFile, line);
        //Get hand of tiles of the player and check if it was a success or not.
        std::shared_ptr<LinkedList> tileList = giveTilesList(line);
        if (tileList == nullptr) {
            isCorrect = false;
        }
        else {
            player->setHand(tileList);
        }
    }
    return isCorrect;
}


std::shared_ptr<LinkedList> FileUtil::giveTilesList(string tileList) {
    std::shared_ptr<LinkedList> tileLL = std::make_shared<LinkedList>();
    string tile = "";
    tileList += ",";
    //Tile string length
    const int tileSize = 2;
    //Traverse over the line to find all the tiles.
    for (unsigned int i = 0; tileLL != nullptr && i < tileList.size(); i++) {
        //check for spaces in tile hand,
        if (tileList[i] != ' ') {
            //If the current char is not a comma.
            if (tileList[i] != ',') {
                //Add the char into string tile.
                tile += tileList[i];
            }
            else {
                //If the current char is a comma.
                //Call to check if the current tile is in correct format or not.
                if (tile.size() != tileSize || !isTileCorrect(tile)) {
                    tileLL = nullptr;
                }
                else {
                    //If the tile is in correct format then store it in the tileLL
                    tileLL->addTile(std::make_shared<Tile>((char)tile[0], ((int)tile[1] - 48)));
                    //Clear the current tile.
                }
                tile = "";
            }
        }
        else {
            tileLL = nullptr;
        }
    }
    return tileLL;
}


bool FileUtil::isTileCorrect(string tile) {
    bool isCorrect = false;
    if (tile.size() == 2) {
        const int shape = (int)tile[1] - 48;
        // check if the shape of tile is in correct range or not.
        if (1 <= shape && shape <= 7) {
            //Looping over the COLOURS array till it founds a correct match or till the end of array.
            for (int index = 0; index < 6 && !isCorrect; index++) {
                //If the colour matches
                if (constants::COLOURS[index] == (char)tile[0]) {
                    isCorrect = true;
                }
            }
        }
    }
    return isCorrect;
}


bool FileUtil::isNameCorrect(const string& name) {
    std::regex regex = std::regex("[a-zA-Z]");
    bool isCorrect = std::regex_search(name, regex);
    //Return
    return isCorrect;
}

std::shared_ptr<GameBoard> FileUtil::getBoard(std::fstream& inputFile) {
    //If earlier input was a success
    std::shared_ptr<GameBoard> gameBoard;
    bool success = true;
    string line = "";
    input_util::getline(inputFile, line);
    //Integer array to store dimensions of the game board.
    int boardSize[2];
    //Loop over the line got through input stream.
    line += ",";
    string dim = "";
    for (unsigned int i = 0, j = 0; i < line.size() && success; i++) {

        if (line[i] != ',') {
            dim += line[i];
        }
        else {
            //Store the dimension into integer array
            boardSize[j] = std::stoi(dim);
            // Check if the dimension falls within the correct range or not.
            if (0 > boardSize[j] || boardSize[j] > 26) {
                //If falls outside the range.
                success = false;
            }
            else {
                j++;
            }
            dim = "";
        }
    }

    if (success) {
        //initialising a new game board object.
        gameBoard = std::make_shared<GameBoard>(boardSize[0], boardSize[1]);

        // Take input for the current state of the board i.e., currently placed tiles on the board.
        input_util::getline(inputFile, line);
        //A Const to check to for the size of each placetile
        const int maxsize = 6;
        const int minsize = 5;
        string placetile = "";
        line += ",";
        //Loop till end of line or the input format till that point is correct.
        if (line.size() > 1 && line != "\n") {
            for (unsigned int index = 0; index < line.size() && gameBoard != nullptr; index++) {
                //Check for comma and a white space.
                if (line[index] != ',' && line[index] != ' ') {
                    placetile += line[index];
                }
                //Check if it is a comma means end of string of one placed tile data and the length of tile is 5 eg. Y5@A1
                else if ((line[index] == ',') && placetile.size() >= minsize && placetile.size() <= maxsize) {
                    //if the tile input is completed.
                    //Create a new tile.
                    string stile = "";
                    stile.append(1, (char)placetile[0]);
                    stile.append(1, (char)placetile[1]);
                    if (isTileCorrect(stile)) {
                        SharedTile tile = std::make_shared<Tile>((char)placetile[0], ((int)placetile[1] - 48));
                        //Place the tile in the game board with the given row and col.
                        int col;
                        //check if the col is in single digit or double digit.
                        if (placetile.size() == minsize) {
                            col = ((int)placetile[4] - 48);
                        }
                        else {
                            string strcol = "";
                            strcol += placetile[4];
                            strcol += placetile[5];
                            col = std::stoi(strcol);
                        }
                        gameBoard->placeTileInLoading(tile, (char)placetile[3], col);
                        //Clear the data for next tile.
                        placetile = "";
                    }
                    else {
                        gameBoard = nullptr;
                    }
                }
                //If it was a comma but the length of tile was not in format.
                else if (line[index] == ',') {
                    gameBoard = nullptr;
                }
            }
        }
    }
    return gameBoard;
}
