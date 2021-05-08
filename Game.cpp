#include "Game.h"

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
    createBoard();
}

void Game::start() {
    while (!isFinished()) {
        std::cout << currentPlayer->getName() << ", it's your turn" << std::endl;
        for (SharedPlayer player : *players) {
            std::cout << "Score for " + player->getName() << ": " << player->getScore() << std::endl;
        }
        //board->displayBoard();
        std::cout << "Your hand is" << std::endl;
        std::string input=input_util::getStringInput()



    }
}

std::string Game::toString() {
    std::string results = "";

    // Getting a string format of all the players in the game
    for (SharedPlayer player : *players) {
        results = results + player->toString();
    }

    // Getting a string format of the board, tileBag and the current player's name
    results = results + this->board->toString();
    results = results + this->tileBag->toString();
    results = results + this->currentPlayer->getName();

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
    //TODO
    //Go through every player
    for (SharedPlayer player : *players) {
        //pick out 6 tiles for the player
        for (int tiles = 0; tiles < 6; tiles++) {
            //select the tile
            std::shared_ptr<Tile> tilePicked = tileBag->getTile(0); //will perhaps change into a shared pointer
            //add the tile to the persons hand.
            players->at(0)->addTile(tilePicked);
            //remove the tile from the tilebag (this is convinient that we are removing the first tiles from the tilebag)
            tileBag->deleteTile(0);
        }
    }
}

void Game::createBoard() {
    //TODO
    
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

void Game::nextPlayerTurn() {

}

