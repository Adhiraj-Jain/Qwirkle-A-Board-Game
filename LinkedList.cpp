
#include "LinkedList.h"

LinkedList::LinkedList() {
   this->head = nullptr;
   this->tail = nullptr;
   this->length = 0;
   // TODO
}

LinkedList::~LinkedList() {
   while (this->head != nullptr)    {
      Node* curr = head;
      head = head->next;
      delete curr;
   }
   this->head = nullptr;
}

bool LinkedList::isEmpty() {
   return (this->size() == 0);
}

int LinkedList::size() {
   return this->length;
}

Tile* LinkedList::getTile(int index) {
   Tile* tile = nullptr;
   // Check for linkedlist and if index is within range or not.
   if (!this->isEmpty() && index >= 0 && index < this->size())    {
      Node* curr = head;
      while (index > 0)       {
         curr = curr->next;
         index--;
      }
      tile = curr->tile;
   }
   return tile;
}

// This method will always add Tile at the back of the LinkedList.
void LinkedList::addTile(Tile* tile) {
   if (tile != nullptr)    {
      Node* newNode = new Node(tile, nullptr);
      if (this->isEmpty())       {
         this->head = newNode;
      }
      else       {
         this->tail->next = newNode;
      }
      this->tail = newNode;
      this->length++;
   }
}

Node* LinkedList::getHead() {
   return this->head;
}

void LinkedList::deleteTile(int index) {
   Tile* tile = nullptr;
   if (!this->isEmpty() && index >= 0 && index < this->size())    {
      Node* curr = head;
      Node* prev = nullptr;

      // loop till you reach at the desired index.
      while (index > 0)       {
         prev = curr;
         curr = curr->next;
         index--;
      }
      // Check if the index is at head position or not.
      if (prev == nullptr)       {
         tile = head->tile;
         this->head = this->head->next;
      }
      else       {
         tile = curr->tile;
         curr = curr->next;
         prev->next = curr;
      }
   }
   this->length--;
   delete tile;
}
