#include "GameBoard.h"

#include <iostream>

GameBoard::GameBoard() {

    this->currentHeight = 0;
    this->currentWidth = 0;

    // Initializing the board with 26 x 26 space
    this->board = std::make_shared<std::vector<std::shared_ptr<std::vector<SharedTile>>>>();
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        std::shared_ptr<std::vector<SharedTile>> row = std::make_shared<std::vector<SharedTile>>(MAX_BOARD_SIZE, nullptr);
        board->push_back(row);
    }

}

bool GameBoard::isValidTileToPlace(SharedTile tile, char row, int col) {
    return true;
}

int GameBoard::mapCharToRow(char target) {
    return (int)target - 65;
}

SharedTile GameBoard::getTile(int row, int col) {
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

int GameBoard::placeTile(SharedTile tile, char rowChar, int col) {
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

    std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> allTilesIn4Direction = this->getAllTilesIn4Direction(row, col);

    return -1;

}


std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> GameBoard::getAllTilesIn4Direction(int row, int col) {

    std::shared_ptr<std::vector<SharedTile>> allTileOnLeft = this->getAllTilesIn1Direction(row, col, 0, 1);
    std::shared_ptr<std::vector<SharedTile>> allTileOnRight = this->getAllTilesIn1Direction(row, col, 0, -1);
    std::shared_ptr<std::vector<SharedTile>> allTileOnUp = this->getAllTilesIn1Direction(row, col, -1, 0);
    std::shared_ptr<std::vector<SharedTile>> allTileOnDown = this->getAllTilesIn1Direction(row, col, 1, 0);

    return nullptr;
}

std::shared_ptr<std::vector<SharedTile>> GameBoard::getAllTilesIn1Direction(int row, int col, int changeInRow, int changeInCol) {

    std::shared_ptr<std::vector<SharedTile>> allLeftTiles = std::make_shared<std::vector<SharedTile>>();
    SharedTile currentTile = this->board->at(row)->at(col);

    while (currentTile != nullptr) {

        allLeftTiles->push_back(currentTile);
        currentTile = this->board->at(row + changeInRow)->at(col + changeInCol);
    }

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

void GameBoard::displayBoard() {
    //printing the numbers
    std::cout << "   ";
    for (unsigned int col = 0; col < board->size(); col++) {
        std::cout << col;
        if(col >= 10)
            std::cout << " ";
        else if(col != board->size() - 1 && col < 10)
            std::cout << "  ";
    }

    std::cout<<std::endl;
    
    //printing the dashed lines
    std::cout << "  ";
    for (unsigned int col = 0; col < board->size(); col++) {
        if(col == 0)
            std::cout << "----";
        else
            std::cout << "---";
    }

    std::cout<<std::endl;
    //printing the tiles
    for(unsigned int row = 0; row < board->size(); row++) {
        
        std::cout << (char) (row + 65) << " |";
        for(unsigned int col = 0; col < board->size(); col++) {
            if(getTile(row,col) == nullptr) {
                std::cout<< "  |";
            }
            else {
                std::cout << getTile(row,col)->toString() << "|";
            }
        }
        std::cout << std::endl;
    }

//    0  1  2  3  4  5
//   -------------------
// A |  |  |  |  |  |  |
// B |  |  |  |  |  |  |
// C |  |  |  |  |  |  |
// D |  |  |  |  |  |  |
// E |  |  |  |  |  |  |
// F |  |  |  |  |  |  |

}


