#ifndef ASSIGN2_GAMEBOARD_H
#define ASSIGN2_GAMEBOARD_H

#include <vector>

class Tile;

class GameBoard {

public:

    // Constructor
    GameBoard();

    // Destructor
    ~GameBoard();

    // Places a tile at the given row and col index
    // Returns true if there was no tile present at the given index
    // Returns false if a tile was present the given index
    bool placeTile(Tile* tile, int row, int col);

    // Returns a tile at the given row and col
    // Returns nullptr if tile not found
    Tile* getTile(int row, int col);

    // Getter methods
    std::vector<std::vector<Tile*>>* getBoard();

private:

    // Class variables
    std::vector<std::vector<Tile*>>* board;
};



#endif // ASSIGN2_GAMEBOARD_H
