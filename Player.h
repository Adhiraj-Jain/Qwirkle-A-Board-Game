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
    Player(string name);

    // Destructor
    ~Player();

    // Adds a Tile to the player's hand with the given tile
    void addTile(const SharedTile& tile);

    // Getter methods
    string getName();

    int getScore();

    /**
     * Whether the player has the given tile on hand
     * @return the tile from the hand, or nullptr if no tile is found
     */
    SharedTile hasTile(Colour color, Shape shape);
    std::shared_ptr<LinkedList> getHand();
    void setHand(std::shared_ptr<LinkedList> hand);
    /**
     * Remove the given tile from the player
     * @return true if tile was found and removed, false otherwise
     */
    bool removeTile(const SharedTile& tile);

    // Adds score to the player
    void addScore(int score);

    // Setter method
    void setScore(int score);

    // ToString method
    string toString();

private:

    // Class Variables
    string name;
    int score;
    std::shared_ptr<LinkedList> hand;

};

#endif // ASSIGN2_PLAYER_H