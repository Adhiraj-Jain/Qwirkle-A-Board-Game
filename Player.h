#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>

class LinkedList;
class Tile;

class Player {

public:

    // Constructor
    Player(std::string name);

    // Destructor
    ~Player();

    // Returns a Tile from the player's hand with the given string value of the tile
    Tile* getTile(std::string tile);

    // Adds a Tile to the player's hand with the given string value of the tile
    void addTile(std::string tile);

    // Adds a Tile to the player's hand with the given tile
    void addTile(Tile* tile);

    // Getter methods
    std::string getName();
    LinkedList* getHand();


private:

    // Class Variables
    std::string name;
    LinkedList* hand;

};

#endif // ASSIGN2_PLAYER_H