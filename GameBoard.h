#ifndef ASSIGN2_GAMEBOARD_H
#define ASSIGN2_GAMEBOARD_H

#include <vector>
#include <string>
#include <memory>
#include "Tile.h"

// class Tile;

class GameBoard {

public:

    // Constructor
    GameBoard();

    //Overloaded Constructor with the width and height of the board
    GameBoard(int currentHeight, int currentWidth);

    // Destructor
    ~GameBoard();

    // Places a tile at the given row and col index
    // Returns the score after place the tile to the give index
    // Returns -1 cannot be added to the given index
    int placeTile(std::shared_ptr<Tile> tile, char row, int col);

    // Returns a tile at the given row and col
    // Returns nullptr if tile not found
    std::shared_ptr<Tile> getTile(char row, int col);

    // Getter methods
    std::shared_ptr<std::vector<std::shared_ptr<std::vector<std::shared_ptr<Tile>>>>> getBoard();

    int getCurrentHight();

    int getCurrentWidth();

    // toString method
    std::string toString();

    //read in board.
    void readBoard();

private:

    // Class variables
    std::shared_ptr<std::vector<std::shared_ptr<std::vector<std::shared_ptr<Tile>>>>> board;
    int currentHeight;
    int currentWidth;

    // Returns a vector of strings of format <tile color><tile shape>@<row index><col index>
    std::shared_ptr<std::vector<std::string>> allTilesWithPos();
};


#endif // ASSIGN2_GAMEBOARD_H
