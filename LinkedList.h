
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include <string>
#include <memory>

class LinkedList {
public:

    //Constructor
    LinkedList();

    //Copy Constructor
    LinkedList(LinkedList& Other);

    //Destructor
    ~LinkedList();

    // Return length of LinkedList
    int size();

    // return Tile at index i
    std::shared_ptr<Tile> getTile(int i);

    // Add tile
    void addTile(std::shared_ptr<Tile> tile);

    //Check if LinkedList is empty or not.
    bool isEmpty();

    // return head
    std::shared_ptr<Node> getHead();

    // delete tile at index i
    void deleteTile(int i);

    // To String method
    std::string toString();

private:
    // Point at the head of Linked List
    std::shared_ptr<Node> head;
    //Point at the tail of the Linked List
    std::shared_ptr<Node> tail;

    //Length of the Linked List
    int length;
};

#endif // ASSIGN2_LINKEDLIST_H
