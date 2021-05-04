#include "Game.h"


// The following code is used to test saving a game
// Game::Game(std::vector<Player*>* players) {
//     this->players = players;
//     this->board = new GameBoard();
//     this->tileBag = new LinkedList();
//     this->currentPlayer = players->at(0);
// }

// Game::~Game() {}

std::string Game::toString() {
    std::string results = "";

    // Getting a string format of all the players in the game
    for (unsigned int index = 0; index < this->players->size(); index++) {
        results = results + this->players->at(index)->toString();
    }

    // Getting a string format of the board, tileBag and the current player's name
    results = results + this->board->toString();
    results = results + this->tileBag->toString();
    results = results + this->currentPlayer->getName();

    return results;
}