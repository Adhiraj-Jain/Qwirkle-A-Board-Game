#ifndef ASSIGN2_GAMEBOARD_H
#define ASSIGN2_GAMEBOARD_H

#include "Tile.h"
#include <vector>
#include <string>
#include <memory>
#include <map>

typedef std::shared_ptr<Tile> SharedTile;

#define MAX_BOARD_SIZE 26

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
    int placeTile(SharedTile tile, char rowChar, int col);

    // Returns a tile at the given row and col
    // Returns nullptr if tile not found
    SharedTile getTile(char row, int col);

    // Getter methods
    std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> getBoard();

    int getCurrentHight();
    int getCurrentWidth();

    // toString method
    std::string toString();

    //read in board.
    void readBoard();

private:

    // Class variables
    std::shared_ptr<std::vector<std::shared_ptr<std::vector<SharedTile>>>> board;
    int currentHeight;
    int currentWidth;
    std::shared_ptr<std::map<char, int>> charToIntMap;

    // Returns a vector of strings of format <tile color><tile shape>@<row index><col index>
    std::shared_ptr<std::vector<std::string>> allTilesWithPos();

    int mapCharToRow(char target);

    int calculateScore(int row, int col);

    bool isValidTileToPlace(std::shared_ptr<Tile> tile, char row, int col);

    std::shared_ptr<std::vector<std::shared_ptr<std::vector<std::shared_ptr<Tile>>>>> getAllTilesIn4Direction(int row, int col);

    std::shared_ptr<std::vector<std::shared_ptr<Tile>>> getAllTilesOnLeft(int row, int col);
};


#endif // ASSIGN2_GAMEBOARD_H
