#include "Game.h"

// The following code is used to test saving a game
Game::Game(std::vector<Player *> *players)
{
    this->players = players;
    this->board = new GameBoard();
    this->tileBag = new LinkedList();
    this->currentPlayer = players->at(0);
}

Game::Game(std::vector<Player *> *players, Player *currentPlayer, GameBoard *board, LinkedList *tileBag)
{
    this->players = players;
    this->currentPlayer = currentPlayer;
    this->board = board;
    this->tileBag = tileBag;
}

Game::initialize()
{
    createTileBag();
    
}

std::string Game::toString()
{
    std::string results = "";

    // Getting a string format of all the players in the game
    for (unsigned int index = 0; index < this->players->size(); index++)
    {
        results = results + this->players->at(index)->toString();
    }

    // Getting a string format of the board, tileBag and the current player's name
    results = results + this->board->toString();
    results = results + this->tileBag->toString();
    results = results + this->currentPlayer->getName();

    return results;
}

void Game::setTileBag(LinkedList *newTileBag)
{
    this->tileBag = newTileBag;
}

void Game::createTileBag()
{
    Colour colours[] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, '/0'};
    Shape shapes[] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};

    //First we would have to create the tile bag
    for (int colour = 0; colour < COLOURS_SIZE; colour++)
    {
        for (int shape = 0; shape < SHAPES_SIZE; shape++)
        {
            Tile *currentTile = new Tile(colours[colour], shapes[shape]); //convert this into a shared pointer probably.
            getTileBag()->addTile(currentTile);
        }
    }
}

void Game::shuffleTileBag()
{
    int TILE_BAG_SIZE = getTileBag()->size();

    //We proceed to then shuffle the tile bag
    //random generators
    std::random_device randomSeed;
    std::uniform_int_distribution<int> uniform_dist(0, TILE_BAG_SIZE - 1);
    //existing positions in new tilebag
    std::vector<int> existingPositions;
    //new shuffled tilebag
    std::shared_ptr<LinkedList> tempTileBag = std::make_shared<LinkedList>();

    // for (int iterations = 0; iterations < TILE_BAG_SIZE; iterations++)
    // {
    //     bool exists = std::find(existingPositions.begin(), existingPositions.end(), iterations) != existingPositions.end();
    //     if(existingPositions.empty() || !exists)
    //     {

    //     }
    // }
}

void Game::setUpPlayerHands()
{
    //TODO
    //Go through every player
    for (int player = 0; player < getPlayers()->size(); player++)
    {
        //pick out 6 tiles for the player
        for (int tiles = 0; tiles < 6; tiles++)
        {
            //select the tile
            Tile *tilePicked = getTileBag()->getTile(0); //will perhaps change into a shared pointer
            //add the tile to the persons hand.
            getPlayers()->at(0)->addTile(tilePicked);
            //remove the tile from the tilebag (this is convinient that we are removing the first tiles from the tilebag)
            getTileBag()->deleteTile(0);
        }
    }
}

void Game::createBoard()
{
    //TODO
    //how would I go about doing this?? Will discuss in meeting
}