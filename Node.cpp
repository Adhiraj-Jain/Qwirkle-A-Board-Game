
#include "Node.h"

Node::Node(SharedTile tile, std::shared_ptr<Node> next) {
    this->tile = tile;
    this->next = next;
}

//Deep copy
Node::Node(Node& other) {
    this->tile = std::make_shared<Tile>(other.tile->getColour(), other.tile->getShape());
    this->next = other.next;
}
