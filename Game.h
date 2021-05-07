#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include <vector>
#include <string>
#include "Player.h"
#include "GameBoard.h"
#include "LinkedList.h"
#include "TileCodes.h"
#include <memory>
#include <random>

// class GameBoard;
// class LinkedList;
// class Player;
class Tile;

class Game {
public:
    // Constructor to create a new Game
    Game(std::vector<Player *> *players);

    // Constructor to create a loaded Game
    Game(std::vector<Player *> *players, Player *currentPlayer, GameBoard *board, LinkedList *tileBag);

    // Destructor
    ~Game();

    // Returns true if the game has reach Qwirkle, false otherwise
    bool isQwirkle();

    // The given tile is added to the tile bag and the new tile is added to the current player's hands
    void playerReplaces(Tile *tile);

    // The given tile is added to the board and a new tile is added to the current player's hand
    void playerPlaces(Tile *tile, int row, int col);

    // Getter Methods
    Player *getCurrentPlayer();

    GameBoard *getBoard();

    LinkedList *getTileBag();

    std::vector<Player *> *getPlayers();

    // toString method
    std::string toString();

    //Setter Methods
    void setTileBag(LinkedList *newTileBag);

    //initialize method
    void initiation();

private:
    // Class Variables
    GameBoard *board;
    LinkedList *tileBag;
    std::vector<Player *> *players;
    Player *currentPlayer;

    // Helper methods

    //Switches the currentPlayer to the next player
    void nextPlayerTurn();

    //Initialize when creating a new game
    void shuffleTileBag();

    void setUpPlayerHands();

    void createBoard();

    void createTileBag();
};

#endif // ASSIGN2_GAME_H