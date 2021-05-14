#include "Game.h"
#include "input_util.h"
#include "FileUtil.h"

#include <utility>
#include <iostream>
#include <sstream>

Game::Game(const std::vector<SharedPlayer>& players) {
    this->players = std::make_shared<std::vector<SharedPlayer>>(players);
    this->board = std::make_shared<GameBoard>();
    this->tileBag = std::make_shared<LinkedList>();
    this->currentPlayer = players.at(0);
}

Game::~Game() = default;

Game::Game(const std::shared_ptr<std::vector<SharedPlayer>> players, SharedPlayer currentPlayer, std::shared_ptr<GameBoard> board,
    std::shared_ptr<LinkedList> tileBag) {
    // clone given player vector
    this->players = players;
    this->currentPlayer = std::move(currentPlayer);
    this->board = std::move(board);
    this->tileBag = std::move(tileBag);
}

void Game::initiation() {
    std::vector<SharedTile> tileVector = createTileBag();   //DONE
    shuffleTileBag(tileVector);  //DONE
    setUpPlayerHands();  //DONE
    createBoard();  //DONE
}

void Game::start() {
    while (!isFinished()) {

        auto lastPlayer = currentPlayer;
        std::cout << std::endl << currentPlayer->getName() << ", it's your turn" << std::endl;
        for (const SharedPlayer& player : *players) {
            std::cout << "Score for " + player->getName() << ": " << player->getScore() << std::endl;
        }
        board->displayBoard();
        std::cout << "Your hand is" << std::endl;
        auto hand = currentPlayer->getHand();
        if (hand->isEmpty())
            std::cout << "<no items>" << std::endl;
        else {
            std::cout << hand->toString() << std::endl;
        }
        // While player hasn't finished their turn
        while (lastPlayer == currentPlayer) {
            string input = input_util::getStringInput(std::regex(COMMAND_REGEX));
            std::stringstream args = std::stringstream(input);
            string command;
            args >> command;
            if (command == "save") {
                string filename;
                args >> filename;
                try {
                    FileUtil::saveGame(filename, this);
                    std::cout << "Game saved successfully" << std::endl;
                }
                catch (const std::exception& ex) {
                    std::cout << "Failed to save: " << ex.what() << std::endl;
                }
            }
            else if (command == "place") {
                string tileStr;
                string pos;
                args >> tileStr;
                // do it twice to filter out the 'at'
                args >> pos;
                args >> pos;
                SharedTile playerTile = currentPlayer->hasTile(tileStr[0], std::stoi(tileStr.substr(1)));
                if (playerTile != nullptr) {
                    int points = board->placeTile(playerTile, pos[0], std::stoi(pos.substr(1)));
                    if (points == -1) {
                        std::cout << "Cannot place a tile here" << std::endl;
                    }
                    else {
                        if(points>=12) {
                            std::cout << "QWIRKLE!" << std::endl;
                        }
                        currentPlayer->removeTile(playerTile);
                        currentPlayer->addScore(points);
                        SharedTile next = tileBag->deleteTile(tileBag->getTile(0));
                        if (next != nullptr)
                            currentPlayer->addTile(next);
                        nextPlayerTurn();
                    }
                }
                else std::cout << "Tile given isn't in your hand" << std::endl;

            }
            else if (command == "replace") {
                string tileStr;
                args >> tileStr;
                SharedTile playerTile = currentPlayer->hasTile(tileStr[0], std::stoi(tileStr.substr(1)));
                if (playerTile != nullptr) {
                    currentPlayer->removeTile(playerTile);
                    tileBag->addTile(playerTile);
                    SharedTile newTile = tileBag->deleteTile(tileBag->getTile(0));
                    currentPlayer->addTile(newTile);
                    std::cout << std::endl << "Added " << newTile->toString() << " to your hand" << std::endl;
                    nextPlayerTurn();
                }
                else
                    std::cout << "Tile given isn't in your hand" << std::endl;

            }
        }
    }
}

string Game::toString() {
    string results = "";

    // Getting a string format of all the players in the game
    for (const SharedPlayer& player : *players) {
        results += player->toString();
    }

    // Getting a string format of the board, tileBag and the current player's name
    results += this->board->toString();
    results += this->tileBag->toString();
    results += this->currentPlayer->getName();

    return results;
}

std::vector<SharedTile> Game::createTileBag() {
    Colour colours[] = { RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE };
    Shape shapes[] = { CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER };

    std::vector<SharedTile> tileVector;

    //First we would have to create the tile bag
    for (char& colour : colours) {
        for (int& shape : shapes) {
            SharedTile currentTile = std::make_shared<Tile>(colour, shape);
            SharedTile currentTile2 = std::make_shared<Tile>(colour, shape);
            tileVector.push_back(currentTile);
            tileVector.push_back(currentTile2);
        }
    }
    return tileVector;
}

void Game::shuffleTileBag(std::vector<SharedTile> tileVector) {

    //Generating a seed for different shuffle every game round
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    //Proceed to shuffle these this tile vector
    std::shuffle(std::begin(tileVector), std::end(tileVector), std::default_random_engine(seed));

    //convert vector into tileBag Linked List
    for (const auto& tile : tileVector) {
        tileBag->addTile(tile);
    }

}

void Game::setUpPlayerHands() {
    //Go through every player
    for (const SharedPlayer& player : *players) {
        //pick out 6 tiles for the player
        for (int tiles = 0; tiles < 6; tiles++) {
            //select the tile
            SharedTile tilePicked = tileBag->deleteTile(tileBag->getTile(0)); //will perhaps change into a shared pointer
            //add the tile to the persons hand.
            player->addTile(tilePicked);
        }
    }
}

void Game::createBoard() {
    //TODO
    // board->displayBoard();

}

bool Game::isFinished() {
    return false;
}

void Game::playerPlaces(SharedTile tile, int row, int col) {

}


SharedPlayer Game::getCurrentPlayer() {
    return currentPlayer;
}

std::shared_ptr<GameBoard> Game::getBoard() {
    return board;
}

std::shared_ptr<LinkedList> Game::getTileBag() {
    return tileBag;
}

std::shared_ptr<std::vector<SharedPlayer>> Game::getPlayers() {
    return players;
}

void Game::playerReplaces(SharedTile tile) {

}

SharedPlayer Game::nextPlayerTurn() {
    SharedPlayer newCurrentPlayer = nullptr;
    for (unsigned int i = 0; i < players->size() && newCurrentPlayer == nullptr; i++) {
        auto player = players->at(i);
        if (player == currentPlayer) {
            currentPlayer = players->at((i + 1) % players->size());
            newCurrentPlayer = currentPlayer;
        }
    }
    return newCurrentPlayer;
}

