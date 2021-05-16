
#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"
#include <memory>

class Node {
public:

    Node(SharedTile tile, std::shared_ptr<Node> next);

    SharedTile tile;
    std::shared_ptr<Node> next;
};

#endif // ASSIGN2_NODE_H
