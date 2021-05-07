
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
   this->tile = tile;
   this->next = next;
}

//Deep copy
Node::Node(Node& other)
{
   this->tile = new Tile(other.tile->getColour(),other.tile->getShape());
   this->next = other.next;
}
