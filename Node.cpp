#include "Node.h"

Node::Node(SharedTile tile, std::shared_ptr<Node> next) {
    this->tile = tile;
    this->next = next;
}