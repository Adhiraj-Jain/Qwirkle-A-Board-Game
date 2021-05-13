
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
        while (index > 1) {
            curr = curr->next;
            index--;
        }
        tile = curr->tile;
    }

    return tile;
}

SharedTile LinkedList::getTile(const Tile & searchTile) {
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
void LinkedList::addTile(SharedTile tile) {
    if (tile != nullptr) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(tile, nullptr);
        if (this->head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            this->tail->next = newNode;
            this->tail = this->tail->next;
        }
        ++this->length;
    }
}

std::shared_ptr<Node> LinkedList::getHead() {
    return this->head;
}

SharedTile LinkedList::deleteTile(int index) {
    SharedTile tile = nullptr;

    if (!this->isEmpty() && index >= 0 && index < this->size()) {
        std::shared_ptr<Node> curr = head;
        std::shared_ptr<Node> prev = nullptr;

        // loop till you reach at the desired index.
        while (index > 0) {
            prev = curr;
            curr = curr->next;
            index--;
        }
        // Check if the index is at head position or not.
        if (prev == nullptr) {
            tile = head->tile;
            this->head = this->head->next;
        }
        else {
            tile = curr->tile;
            curr = curr->next;
            prev->next = curr;
        }
        this->length--;
    }

    return tile;
}

string LinkedList::toString() {
    string result = "";
    int index = 0;
    // Get and converts each tile in the list to a string
    std::shared_ptr<Node> curr = head;
    while (curr != nullptr) {
        result = result + curr->tile->toString();
        if (index + 1 != this->length) {
            result = result + ",";
        }
        index++;
        curr = curr->next;
    }
    // for (; index < this->length; ) {
    //     result = result + this->getTile(index)->toString();

    //     // Does not produce a comma after the last tile

    // }

    return result + "\n";
}

