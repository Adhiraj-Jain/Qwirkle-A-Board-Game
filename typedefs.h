#ifndef ASSIGN2_TYPEDEFS_H
#define ASSIGN2_TYPEDEFS_H
#include <vector>

class Tile;

class Player;

// Define a Colour type (Tile)
typedef char Colour;

// Define a Shape type (Tile)
typedef int Shape;

typedef std::shared_ptr<Tile> SharedTile;
typedef std::shared_ptr<Player> SharedPlayer;
typedef std::string string;
template<typename T> using SharedVector = std::shared_ptr<std::vector<T>>;

#endif //ASSIGN2_TYPEDEFS_H
