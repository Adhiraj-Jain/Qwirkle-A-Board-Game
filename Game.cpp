#include "Game.h"
#include "input_util.h"
#include "FileUtil.h"

#include <utility>
#include <iostream>


Game::Game(const std::vector<SharedPlayer> &players) {
    this->players = std::make_shared<std::vector<SharedPlayer>>(players);
    this->board = std::make_shared<GameBoard>();
    this->tileBag = std::make_shared<LinkedList>();
    this->currentPlayer = players.at(0);
}

Game::~Game() = default;

Game::Game(const std::vector<SharedPlayer> &players, SharedPlayer currentPlayer, std::shared_ptr<GameBoard> board,
           std::shared_ptr<LinkedList> tileBag) {
    // clone given player vector
    this->players = std::make_shared<std::vector<SharedPlayer>>(players);
    this->currentPlayer = std::move(currentPlayer);
    this->board = std::move(board);
    this->tileBag = std::move(tileBag);
}

void Game::initiation() {
    createTileBag();   //DONE
    shuffleTileBag();  //DONE
    setUpPlayerHands();  //DONE
    createBoard();  //DONE
}

void Game::start() {

    while (!isFinished()) {
        auto lastPlayer = currentPlayer;
        std::cout << currentPlayer->getName() << ", it's your turn" << std::endl;
        for (const SharedPlayer &player : *players) {
            std::cout << "Score for " + player->getName() << ": " << player->getScore() << std::endl;
        }
        board->displayBoard();
        std::cout << "Your hand is" << std::endl;
        auto hand = currentPlayer->getHand();
        if (hand->isEmpty())
            std::cout << "<no items>" << std::endl;
        else {
            for (int i = 0; i < hand->size(); i++) {
                auto handTile = hand->getTile(i);
                std::cout << handTile->getColour() << handTile->getShape()
                          // if last element, don't put a comma at the end
                          << (i == hand->size() - 1 ? "" : ",");
            }
            std::cout << std::endl;
        }
        // While player hasn't finished their turn
        while (lastPlayer == currentPlayer) {
            std::string input = input_util::getStringInput(std::regex(COMMAND_REGEX));
            std::stringstream args = std::stringstream(input);
            std::string command;
            args >> command;
            if (command == "save") {
                std::string filename;
                args >> filename;
                try {
                    FileUtil::saveGame(filename, this);
                    std::cout << "Game saved successfully" << std::endl;
                } catch (const std::exception &ex) {
                    std::cout << "Failed to save: " << ex.what() << std::endl;
                }
            } else if (command == "place") {
                std::string tileStr;
                std::string pos;
                args >> tileStr;
                // do it twice to filter out the 'at'
                args >> pos;
                args >> pos;
                SharedTile playerTile = currentPlayer->hasTile(tileStr[0], std::stoi(tileStr.substr(1)));
                if (playerTile != nullptr) {
                    int points = board->placeTile(playerTile, pos[0], std::stoi(pos.substr(1)));
                    if (points == -1) {
                        std::cout << "Cannot place a tile here" << std::endl;
                    } else {
                        currentPlayer->removeTile(playerTile);
                        currentPlayer->setScore(currentPlayer->getScore() + points);
                        nextPlayerTurn();
                    }
                } else std::cout << "Tile given isn't in your hand" << std::endl;

            } else if (command == "replace") {
                std::string tileStr;
                args >> tileStr;
                SharedTile playerTile = currentPlayer->hasTile(tileStr[0], std::stoi(tileStr.substr(1)));
                if (playerTile != nullptr) {
                    currentPlayer->removeTile(playerTile);
                    tileBag->addTile(playerTile);
                    SharedTile newTile = tileBag->deleteTile(0);
                    currentPlayer->addTile(newTile);
                    std::cout << "Added " << newTile->toString() << " to your hand" << std::endl;
                    nextPlayerTurn();
                } else
                    std::cout << "Tile given isn't in your hand" << std::endl;

            }
        }
    }
}

std::string Game::toString() {
    std::string results = "";

    // Getting a string format of all the players in the game
    for (const SharedPlayer &player : *players) {
        results += player->toString();
    }

    // Getting a string format of the board, tileBag and the current player's name
    results += this->board->toString();
    results += this->tileBag->toString();
    results += this->currentPlayer->getName();

    return results;
}

void Game::setTileBag(std::shared_ptr<LinkedList> newTileBag) {
    this->tileBag = std::move(newTileBag);
}

void Game::createTileBag() {
    Colour colours[] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    Shape shapes[] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};

    //First we would have to create the tile bag
    for (char &colour : colours) {
        for (int &shape : shapes) {
            std::shared_ptr<Tile> currentTile = std::make_shared<Tile>(colour, shape);
            tileBag->addTile(currentTile);
        }
    }
}

void Game::shuffleTileBag() {

    //First create all values into shared pointer vector quantities of Tiles
    std::vector<std::shared_ptr<Tile>> tileVector;

    for (int tile = 0; tile < getTileBag()->size(); tile++) {
        std::shared_ptr<Tile> tempTile = getTileBag()->getTile(tile);
        tileVector.push_back(tempTile);
    }

    //Then proceed to shuffle these Tiles
    std::shuffle(std::begin(tileVector), std::end(tileVector), std::default_random_engine());

    std::shared_ptr<LinkedList> newTileBag = std::make_shared<LinkedList>();
    for (const auto &tile : tileVector) {
        newTileBag->addTile(tile);
    }

    //Then add them back into a new LinkedList and put all values of the vector back inside the tileBag and then setTileBag LinkedList at the end.
    setTileBag(newTileBag);
}

void Game::setUpPlayerHands() {
    //Go through every player
    for (const SharedPlayer &player : *players) {
        //pick out 6 tiles for the player
        for (int tiles = 0; tiles < 6; tiles++) {
            //select the tile
            SharedTile tilePicked = tileBag->deleteTile(0); //will perhaps change into a shared pointer
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

void Game::playerPlaces(std::shared_ptr<Tile> tile, int row, int col) {

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

void Game::playerReplaces(std::shared_ptr<Tile> tile) {

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

