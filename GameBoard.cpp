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

GameBoard::GameBoard(int height, int width) :GameBoard() {
    this->currentHeight = height;
    this->currentWidth = width;
}

int GameBoard::mapCharToRow(char target) {
    return (int)target - 65;
}

char GameBoard::mapRowToChar(int target) {
    return (char)(target + 65);
}

SharedTile GameBoard::getTile(int row, int col) {
    return this->board->at(row)->at(col);
}

int GameBoard::getCurrentHeight() {
    return this->currentHeight;
}

int GameBoard::getCurrentWidth() {
    return this->currentWidth;
}

GameBoard::~GameBoard() = default;


std::shared_ptr<std::vector<string>> GameBoard::allTilesWithPos() {
    std::shared_ptr<std::vector<string>> tilesString = std::make_shared<std::vector<string>>();

    // Iterates over the rows in the board
    for (int row = 0; row < this->currentHeight; row++) {

        // Iterates over the cols in the board
        for (int col = 0; col < this->currentWidth; col++) {
            SharedTile tile = this->board->at(row)->at(col);

            // Builds a string of the tile at the position in format <colour><shape>@<row><col>
            if (tile != nullptr) {
                tilesString->push_back(tile->toString() + "@" + this->mapRowToChar(row) + std::to_string(col));
            }
        }
    }
    return tilesString;
}

int GameBoard::placeTile(const SharedTile & tile, char rowChar, int col) {

    int score = -1;
    int row = this->mapCharToRow(rowChar);
    // Checks if the row and col is not out of the board dimensions
    if (row <= MAX_BOARD_SIZE && col <= MAX_BOARD_SIZE) {

        // Checks if there is no tile at row and col, and checks if that tile is legal to place at row and col
        // If the validation is true, then it will place the tile and calculate the score 
        if (this->getTile(row, col) == nullptr && this->isValidTileToPlace(tile, row, col)) {

            this->board->at(row)->at(col) = tile;
            score = this->calculateScore(row, col);

            // Change current height and width
            if (row + 1 > this->currentHeight) {
                this->currentHeight = row + 1;
            }
            if (col + 1 > this->currentWidth) {
                this->currentWidth = col + 1;
            }
        }
    }
    return score;
}

bool GameBoard::isValidTileToPlace(const SharedTile & tile, int row, int col) {
    bool valid = true;
    std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> allTilesIn2Direction = this->getAllTilesIn2Direction(row, col);

    // Iterates of all of the directions (left-right and up-down) and until the tile is valid to place
    for (unsigned int i = 0; i < allTilesIn2Direction->size() && valid; i++) {
        std::shared_ptr<std::vector<SharedTile>> tilesIn1Direction = allTilesIn2Direction->at(i);

        // Checks the placed tile does not add to the Qwirkle
        if (tilesIn1Direction->size() < QWIRKLE_LENGTH) {

            // Iterates over all the tiles in each directions and until the tile is valid to place
            for (unsigned int j = 0; j < tilesIn1Direction->size() && valid; j++) {
                SharedTile currentTile = tilesIn1Direction->at(j);

                // The tile is not valid if the two tiles are same or both the shape and the colour are not different
                if (currentTile->isEqual(tile) || (currentTile->getShape() != tile->getShape() && currentTile->getColour() != tile->getColour())) {
                    valid = false;
                }
            }
        }
    }
    return valid;
}


int GameBoard::calculateScore(int row, int col) {
    int score = 0;
    std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> allTilesIn4Direction = this->getAllTilesIn2Direction(row, col);

    // Iterates over the 4 directions (left, right, up, down)
    for (auto tilesIn1Direction : *allTilesIn4Direction) {
        unsigned int size = tilesIn1Direction->size();

        // If there is a tile in a direction then increase score by the size
        if (size > 0) {

            // This is Qwirkle! If a direction has 5 tiles, it add 6 points
            if (size == QWIRKLE_LENGTH - 1) {
                score += QWIRKLE_POINTS;
            }
            score += size + 1;
        }
    }

    // This condition is true if there is only tile in the board
    if (score == 0) {
        score += 1;
    }
    return score;
}


std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> GameBoard::getAllTilesIn2Direction(int row, int col) {

    std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> tiles = std::make_shared<std::vector<std::shared_ptr<std::vector<SharedTile>>>>();

    // Get tiles from each direction and add it in a vector
    std::shared_ptr<std::vector<SharedTile>> getAllTilesLeft = this->getAllTilesIn1Direction(row, col, 0, -1);
    std::shared_ptr<std::vector<SharedTile>> getAllTilesRight = this->getAllTilesIn1Direction(row, col, 0, 1);
    std::shared_ptr<std::vector<SharedTile>> getAllTilesUp = this->getAllTilesIn1Direction(row, col, -1, 0);
    std::shared_ptr<std::vector<SharedTile>> getAllTilesDown = this->getAllTilesIn1Direction(row, col, 1, 0);

    // Merging the left and up vectors with right and down vectors of tiles respectively
    tiles->push_back(addTwoVectors(getAllTilesLeft, getAllTilesRight));
    tiles->push_back(addTwoVectors(getAllTilesUp, getAllTilesDown));


    return tiles;
}


std::shared_ptr<std::vector<SharedTile>> GameBoard::addTwoVectors(std::shared_ptr<std::vector<SharedTile>> vector1, std::shared_ptr<std::vector<SharedTile>> vector2) {

    // Loops and adds all the elements from vector1 into vector2
    for (auto element : *vector1) {
        vector2->push_back(element);
    }
    return vector2;
}

std::shared_ptr<std::vector<SharedTile>> GameBoard::getAllTilesIn1Direction(int row, int col, int changeInRow, int changeInCol) {

    std::shared_ptr<std::vector<SharedTile>> tiles = std::make_shared<std::vector<SharedTile>>();

    SharedTile currentTile = nullptr;

    // Loop till the current tile is not a null_ptr (i.e. no more tiles to loop through in one direction)
    do {

        // For the initial iteration of the loop, the condition is always true after the first iteration
        if (currentTile != nullptr) {
            tiles->push_back(currentTile);
        }

        row += changeInRow;
        col += changeInCol;

        // Checks if the new row and col are not out of bound of the board dimensions
        if (row >= 0 && col >= 0 && row <= MAX_BOARD_SIZE - 1 && col <= MAX_BOARD_SIZE - 1) {
            currentTile = this->board->at(row)->at(col);
        }
        else {
            currentTile = nullptr;
        }

    } while (currentTile != nullptr);
    return tiles;
}

std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> GameBoard::getBoard() {
    return this->board;
}

string GameBoard::toString() {
    string result = std::to_string(this->currentHeight) + "," + std::to_string(this->currentWidth) + "\n";

    // Gets all the tiles in the board with their positions
    std::shared_ptr<std::vector<string>> tilesWithPos = this->allTilesWithPos();

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
        if (col >= 10) {
            std::cout << " ";
        }
        else if (col != board->size() - 1 && col < 10) {
            std::cout << "  ";
        }
    }

    std::cout << std::endl;

    //printing the dashed lines
    std::cout << "  ";
    for (unsigned int col = 0; col < board->size(); col++) {
        if (col == 0) {
            std::cout << "----";
        }
        else {
            std::cout << "---";
        }
    }

    std::cout << std::endl;
    //printing the tiles
    for (unsigned int row = 0; row < board->size(); row++) {

        std::cout << this->mapRowToChar(row) << " |";
        for (unsigned int col = 0; col < board->size(); col++) {
            if (getTile(row, col) == nullptr) {
                std::cout << "  |";
            }
            else {
                std::cout << getTile(row, col)->toString() << "|";
            }
        }
        std::cout << std::endl;
    }
}

