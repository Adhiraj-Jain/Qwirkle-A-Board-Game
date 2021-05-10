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
#include <chrono>

// class GameBoard;
// class LinkedList;
// class Player;
// class Tile;

class Game {
public:
    // Constructor to create a new Game
    Game(const std::vector<SharedPlayer>& players);

    // Constructor to create a loaded Game
    Game(const std::shared_ptr<std::vector<SharedPlayer>> players, SharedPlayer currentPlayer, std::shared_ptr<GameBoard> board,
        std::shared_ptr<LinkedList> tileBag);

    // Destructor
    ~Game();
    /**
     * Whether the game has finished and there's a winner
     */
    bool isFinished();

    // The given tile is added to the tile bag and the new tile is added to the current player's hands
    void playerReplaces(SharedTile tile);

    // The given tile is added to the board and a new tile is added to the current player's hand
    void playerPlaces(SharedTile tile, int row, int col);

    // Getter Methods
    SharedPlayer getCurrentPlayer();

    std::shared_ptr<GameBoard> getBoard();

    std::shared_ptr<LinkedList> getTileBag();

    std::shared_ptr<std::vector<SharedPlayer>> getPlayers();

    // toString method
    string toString();

    //initialize method
    void initiation();
    /**
     * Blocking method which starts the game and doesn't return until the game is finished.
     */
    void start();

private:
    // Class Variables
    std::shared_ptr<GameBoard> board;
    std::shared_ptr<LinkedList> tileBag;
    std::shared_ptr<std::vector<SharedPlayer>> players;
    SharedPlayer currentPlayer;

    // Helper methods

    /**
     * Moves the game to the next player turn
     * @return the next player
     */
    SharedPlayer nextPlayerTurn();

    //Initialize when creating a new game
    void shuffleTileBag(std::vector<SharedTile> tileVector);

    void setUpPlayerHands();

    void createBoard();

    std::vector<SharedTile> createTileBag();
};

#endif // ASSIGN2_GAME_H