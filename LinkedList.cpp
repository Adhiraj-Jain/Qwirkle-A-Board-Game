
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

LinkedList::~LinkedList() = default;

bool LinkedList::isEmpty() {
    return (this->size() == 0);
}

int LinkedList::size() {
    return this->length;
}

SharedTile LinkedList::getTile(int index) {
    SharedTile tile = nullptr;
    // Check for linkedlist and if index is within range or not.
    if (!this->isEmpty() && index >= 0 && index < this->size()) {
        std::shared_ptr<Node> curr = head;
        for (int i=0;i<index;i++){
            curr=curr->next;
        }
        tile = curr->tile;
    }

    return tile;
}

SharedTile LinkedList::getTile(const Tile& searchTile) {
    // Check for linkedlist and if index is within range or not.
    SharedTile tile = nullptr;
    std::shared_ptr<Node> curr = head;
    while (tile == nullptr && curr != nullptr) {
        if (curr->tile->isEqual(searchTile)) {
            tile = curr->tile;
        }
        curr = curr->next;
    }
    return tile;
}

// This method will always add Tile at the back of the LinkedList.
void LinkedList::addTile(const SharedTile& tile) {
    if (tile != nullptr) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(tile, nullptr);
        if (this->head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        ++this->length;
    }
}

SharedTile LinkedList::deleteTile(const SharedTile & toRemove) {
    SharedTile tile = nullptr;

    if (!this->isEmpty()) {
        std::shared_ptr<Node> curr = head;
        std::shared_ptr<Node> prev = nullptr;

        while (curr != nullptr && tile == nullptr) {
            // same memory location
            if (toRemove==curr->tile) {
                // middle or end of the list
                if (prev != nullptr) {
                    prev->next = curr->next;
                }
                // beginning of list
                else {
                    head = curr->next;
                }
                if(curr==tail){
                    this->tail=prev;
                }
                tile = curr->tile;
                // For development only. Production will never enter this state
                if(tile == nullptr)
                    throw std::runtime_error("Reached illegal state - nullptr in list tree. Terminating...");
                length--;
            }

            prev = curr;
            curr = curr->next;
        }
    }
    return tile;
}

string LinkedList::toString() {
    string result = "";

    // Get and converts each tile in the list to a string
    std::shared_ptr<Node> curr = head;
    while (curr != nullptr) {
        result += curr->tile->toString();

        // Does not produce a comma after the last tile
        if (curr->next != nullptr) {
            result += ",";
        }
        curr = curr->next;
    }

    return result + "\n";
}

