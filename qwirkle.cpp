
#include "LinkedList.h"
#include "QwirkleGameEngine.h"
#include <iostream>

#define EXIT_SUCCESS 0

int main(void) {
    LinkedList* list = new LinkedList();
    delete list;

    std::cout << "Welcome to Qwirkle" << std::endl;
    std::cout << "------------------" << std::endl;

    GameBoard* gameBoard = new GameBoard();

    // std::cout << gameBoard->getBoard()->size() << std::endl;
    // std::cout << gameBoard->getBoard()->at(1)->size() << std::endl;

    std::cout << "Score: " << gameBoard->placeTile(std::make_shared<Tile>('A', 1), 'A', 0) << std::endl;
    std::cout << "Score: " << gameBoard->placeTile(std::make_shared<Tile>('A', 2), 'A', 1) << std::endl;
    std::cout << "Score: " << gameBoard->placeTile(std::make_shared<Tile>('A', 3), 'A', 2) << std::endl;
    std::cout << "Score: " << gameBoard->placeTile(std::make_shared<Tile>('A', 4), 'A', 3) << std::endl;
    std::cout << "Score: " << gameBoard->placeTile(std::make_shared<Tile>('A', 5), 'A', 4) << std::endl;
    std::cout << "Score: " << gameBoard->placeTile(std::make_shared<Tile>('A', 6), 'A', 5) << std::endl;


    // std::cout << gameBoard->toString() << std::endl;
    // std::cout << gameBoard->getTile(3, 4)->toString();

    // std::cout << gameBoard->toString();
    // std::cout << "end" << std::endl;

    QwirkleGameEngine* engine = new QwirkleGameEngine();
    engine->start();

    delete engine;
    return EXIT_SUCCESS;
}
