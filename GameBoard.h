#ifndef ASSIGN2_GAMEBOARD_H
#define ASSIGN2_GAMEBOARD_H

#include "Tile.h"
#include <vector>
#include <string>
#include <memory>

#define MAX_BOARD_SIZE 26
#define QWIRKLE_LENGTH 6
#define QWIRKLE_POINTS 6

class GameBoard {

public:

    // Constructor
    GameBoard();

    //Overloaded Constructor with the width and height of the board
    GameBoard(int currentHeight, int currentWidth);

    // Destructor
    ~GameBoard();

    // Places a tile at the given row and col index
    // Returns the score after place the tile to the given index
    // Returns -1, if the tile cannot be added to the given index
    int placeTile(const SharedTile& tile, char rowChar, int col);

    // Returns a tile at the given row and col
    // Returns nullptr if tile not found
    SharedTile getTile(int row, int col);

    // Getter methods
    std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> getBoard();
    int getCurrentHeight();
    int getCurrentWidth();

    // toString method
    string toString();

    //read in board.
    void displayBoard();

private:

    // Class variables
    std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> board;
    int currentHeight;
    int currentWidth;

    // Returns a vector of strings of format <tile color><tile shape>@<row index><col index>
    std::shared_ptr<std::vector<string>> allTilesWithPos();

    // Returns an integer from 0-25 for characters A-Z
    int mapCharToRow(char target);

    // Returns an character from A-Z for integer 0-25
    char mapRowToChar(int target);

    // Returns a score for the tile add at given index
    int calculateScore(int row, int col);

    // Validates if the tile at the given index if a legal placement
    // Returns true if legal, false if illegal
    bool isValidTileToPlace(const SharedTile& tile, char row, int col);

    // This method collects all the Tiles from all four directions of the given index
    // i.e. it returns all the Tiles in (left and right combined, up and down combined) of the given row and col
    std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> getAllTilesIn2Direction(int row, int col);

    // This method collects all the Tiles from one direction of the given index
    // The changeInRow and ChangeInCol specifies the direction
    std::shared_ptr<std::vector<SharedTile>> getAllTilesIn1Direction(int row, int col, int changeInRow, int changeInCol);

    // Appends vector1 at the back of vector2
    std::shared_ptr<std::vector<SharedTile>> addTwoVectors(std::shared_ptr<std::vector<SharedTile>> vector1, std::shared_ptr<std::vector<SharedTile>> vector2);
};


#endif // ASSIGN2_GAMEBOARD_H
