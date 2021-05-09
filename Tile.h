#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <string>
#include <memory>

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {

public:

    // Constructor
    Tile(Colour colour, Shape shape);

    //Checks if two tiles are equal
    bool isEqual(const std::shared_ptr<Tile> tile);

    // Getter methods
    Colour getColour();
    Shape getShape();

    // ToString method
    std::string toString();

private:

    // Class variables
    Colour colour;
    Shape shape;
};

#endif // ASSIGN2_TILE_H