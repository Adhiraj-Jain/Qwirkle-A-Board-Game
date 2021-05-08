#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include <vector>
#include <string>
#include "Player.h"
#include "GameBoard.h"
#include "LinkedList.h"
#include "TileCodes.h"
#include "Tile.h"
#include <memory>
#include <random>
#include <algorithm>

// class GameBoard;
// class LinkedList;
// class Player;
// class Tile;

class Game {
public:
    // Constructor to create a new Game
    Game(std::shared_ptr<std::vector<std::shared_ptr<Player>>> players);

    // Constructor to create a loaded Game
    Game(std::shared_ptr<std::vector<std::shared_ptr<Player>>> players, std::shared_ptr<Player> currentPlayer, std::shared_ptr<GameBoard> board, std::shared_ptr<LinkedList> tileBag);

    // Destructor
    ~Game();

    // Returns true if the game has reach Qwirkle, false otherwise
    bool isQwirkle();

    // The given tile is added to the tile bag and the new tile is added to the current player's hands
    void playerReplaces(std::shared_ptr<Tile> tile);

    // The given tile is added to the board and a new tile is added to the current player's hand
    void playerPlaces(std::shared_ptr<Tile> tile, int row, int col);

    // Getter Methods
    std::shared_ptr<Player> getCurrentPlayer();
    std::shared_ptr<GameBoard> getBoard();
    std::shared_ptr<LinkedList> getTileBag();
    std::shared_ptr<std::vector<std::shared_ptr<Player>>> getPlayers();

    // toString method
    std::string toString();

    //Setter Methods
    void setTileBag(std::shared_ptr<LinkedList> newTileBag);

    //initialize method
    void initiation();

private:
    // Class Variables
    std::shared_ptr<GameBoard> board;
    std::shared_ptr<LinkedList> tileBag;
    std::shared_ptr<std::vector<std::shared_ptr<Player>>> players;
    std::shared_ptr<Player> currentPlayer;

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