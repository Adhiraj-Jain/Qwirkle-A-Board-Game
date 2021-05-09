//
// Created by ryan9 on 9/05/2021.
//

#ifndef ASSIGN2_TYPEDEFS_H
#define ASSIGN2_TYPEDEFS_H

class Tile;

class Player;

// Define a Colour type (Tile)
typedef char Colour;

// Define a Shape type (Tile)
typedef int Shape;

typedef std::shared_ptr<Tile> SharedTile;
typedef std::shared_ptr<Player> SharedPlayer;
typedef std::string string;


#endif //ASSIGN2_TYPEDEFS_H