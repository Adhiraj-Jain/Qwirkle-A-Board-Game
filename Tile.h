#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <string>
#include <memory>
#include "typedefs.h"


class Tile {

public:

    // Constructor
    Tile(Colour colour, Shape shape);

    bool isEqual(const Tile &tile);

    // Getter methods
    Colour getColour();

    Shape getShape();

    // ToString method
    string toString();

private:

    // Class variables
    Colour colour;
    Shape shape;


};

#endif // ASSIGN2_TILE_H