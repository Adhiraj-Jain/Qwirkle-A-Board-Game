#ifndef ASSIGN2_GAMEBOARD_H
#define ASSIGN2_GAMEBOARD_H

#include <vector>
#include <string>

class Tile;

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
    int placeTile(Tile* tile, char row, int col);

    // Returns a tile at the given row and col
    // Returns nullptr if tile not found
    Tile* getTile(char row, int col);

    // Getter methods
    std::vector<std::vector<Tile*>>* getBoard();

    int getCurrentHight();

    int getCurrentWidth();

    // toString method
    std::string toString();


private:

    // Class variables
    std::vector<std::vector<Tile*>>* board;
    int currentHeight;
    int currentWidth;

    // Returns a vector of strings of format <tile color><tile shape>@<row index><col index>
    std::vector<std::string>* allTilesWithPos();
};


#endif // ASSIGN2_GAMEBOARD_H
