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

std::string Tile::toString() {
    return this->colour + std::to_string(this->shape);
}

bool Tile::isEqual(const std::shared_ptr<Tile> tile) {
    return this->shape == tile->shape && this->colour == tile->colour;
}
