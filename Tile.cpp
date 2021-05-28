#include "Tile.h"

Tile::Tile(Colour colour, Shape shape) {
    this->colour = colour;
    this->shape = shape;
}

Shape Tile::getShape() {
    return shape;
}

Colour Tile::getColour() {
    return colour;
}

string Tile::toString(bool isColour) {
    string tile = "";
    if (isColour) {
        if (this->colour == RED) {
            tile += RED_C;
        }
        else if (this->colour == ORANGE) {
            tile += ORANGE_C;
        }
        else if (this->colour == YELLOW) {
            tile += YELLOW_C;
        }
        else if (this->colour == GREEN) {
            tile += GREEN_C;
        }
        else if (this->colour == BLUE) {
            tile += BLUE_C;
        }
        else if (this->colour == PURPLE) {
            tile += MAGENTA_C;
        }
        tile += this->colour + std::to_string(this->shape) + RESET;
    }
    else {
        tile = this->colour + std::to_string(this->shape);
    }
    return tile;
}

bool Tile::isEqual(const Tile& tile) {
    return this->shape == tile.shape && this->colour == tile.colour;
}
