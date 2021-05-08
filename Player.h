#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>
#include "LinkedList.h"
#include "Tile.h"
#include <memory>

// class LinkedList;
// class Tile;

class Player {

public:

    // Constructor
    Player(std::string name);

    // Destructor
    ~Player();

    // Returns a Tile from the player's hand with the given string value of the tile
    std::shared_ptr<Tile> getTile(std::string tile);

    // Adds a Tile to the player's hand with the given tile
    void addTile(std::shared_ptr<Tile> tile);

    // Getter methods
    std::string getName();

    int getScore();

    /**
     * Whether the player has the given tile on hand
     */
    bool hasTile(Colour color, Shape shape);
    std::shared_ptr<LinkedList> getHand();

    // Setter method
    void setScore(int score);

    // ToString method
    std::string toString();

private:

    // Class Variables
    std::string name;
    int score;
    std::shared_ptr<LinkedList> hand;

};

#endif // ASSIGN2_PLAYER_H