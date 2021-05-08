#include "GameBoard.h"

GameBoard::GameBoard() {

    this->currentHeight = 0;
    this->currentWidth = 0;

    this->charToIntMap = std::make_shared<std::map<char, int>>();
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {

    }

}

bool GameBoard::isValidTileToPlace(std::shared_ptr<Tile> tile, char row, int col) {
    return true;
}
int GameBoard::mapCharToRow(char target) {
    return -1;
}

std::shared_ptr<Tile> GameBoard::getTile(char row, int col) {
    return nullptr;
}

GameBoard::GameBoard(int height, int width) {
    this->currentHeight = height;
    this->currentWidth = width;
}

GameBoard::~GameBoard() {}


std::shared_ptr<std::vector<std::string>> GameBoard::allTilesWithPos() {
    return nullptr;
}

int GameBoard::placeTile(std::shared_ptr<Tile> tile, char rowChar, int col) {
    int score = -1;
    int row = this->mapCharToRow(rowChar);

    if (row <= MAX_BOARD_SIZE && col <= MAX_BOARD_SIZE) {

        if (this->getTile(row, col) == nullptr && this->isValidTileToPlace(tile, row, col)) {

            this->board->at(row)->at(col) = tile;
            score = this->calculateScore(row, col);

            if (row > this->currentHeight) {
                this->currentHeight = row;
            }

            if (col > this->currentWidth) {
                this->currentWidth = col;
            }
        }
    }
    return score;
}

int GameBoard::calculateScore(int row, int col) {

    std::shared_ptr<std::vector<std::shared_ptr<std::vector<std::shared_ptr<Tile>>>>> allTilesIn4Direction = this->getAllTilesIn4Direction(row, col);

    return -1;

}


std::shared_ptr<std::vector<std::shared_ptr<std::vector<std::shared_ptr<Tile>>>>> GameBoard::getAllTilesIn4Direction(int row, int col) {

    std::shared_ptr<std::vector<std::shared_ptr<Tile>>> allTileOnLeft = this->getAllTilesOnLeft(row, col);
    std::shared_ptr<std::vector<std::shared_ptr<Tile>>> allTileOnRight;
    std::shared_ptr<std::vector<std::shared_ptr<Tile>>> allTileOnUp;
    std::shared_ptr<std::vector<std::shared_ptr<Tile>>> allTileOnDown;

    return nullptr;
}

std::shared_ptr<std::vector<std::shared_ptr<Tile>>> GameBoard::getAllTilesOnLeft(int row, int col) {

    std::shared_ptr<std::vector<std::shared_ptr<Tile>>> allLeftTiles = std::make_shared<std::vector<std::shared_ptr<Tile>>>();

    return allLeftTiles;

}



std::string GameBoard::toString() {
    std::string result = std::to_string(this->currentHeight) + "," + std::to_string(this->currentWidth) + "\n";

    // Gets all the tiles in the board with their positions
    std::shared_ptr<std::vector<std::string>> tilesWithPos = this->allTilesWithPos();

    // Appends each string from the vector to the result
    for (unsigned int index = 0; index < tilesWithPos->size(); index++) {
        result = result + tilesWithPos->at(index);

        // Ignores a comma after the last tile
        if (index + 1 != tilesWithPos->size()) {
            result = result + ", ";
        }
    }
    return result + "\n";
}



