#include "GameBoard.h"

// The following code is used to test saving a game
GameBoard::GameBoard() {
    this->currentHeight = 0;
    this->currentWidth = 0;
}

GameBoard::GameBoard(int height, int width) {
    this->currentHeight = height;
    this->currentWidth = width;
}

// GameBoard::~GameBoard() {}

// bool GameBoard::placeTile(Tile* tile, char row, int col) { return true; }


// The following code is used to test saving a game
std::vector<std::string>* GameBoard::allTilesWithPos() {
    std::vector<std::string>* vec = new std::vector<std::string>();
    vec->push_back("B4@B2");
    vec->push_back("B6@B3");

    return vec;
}

std::string GameBoard::toString() {
    std::string result = std::to_string(this->currentHeight) + "," + std::to_string(this->currentWidth) + "\n";


    // Gets all the tiles in the board with their positions
    std::vector<std::string>* tilesWithPos = this->allTilesWithPos();

    // Appends each string from the vector to the result
    for (unsigned int index = 0; index < tilesWithPos->size(); index++) {
        result = result + tilesWithPos->at(index);

        // Ignores a comma after the last tile
        if (index + 1 != tilesWithPos->size()) {
            result = result + ",";
        }
    }
    return result + "\n";
}