#include "QwirkleGameEngine.h"
#include <iostream>

#define EXIT_SUCCESS 0

int main(int argc, char **argv) {
    std::cout << "Welcome to Qwirkle" << std::endl;
    std::cout << "------------------" << std::endl;

    QwirkleGameEngine *engine = nullptr;
    // we accept one parameter, a seed for testing. If future enhancements add more commandline args, this code must
    // be improved
    if (argc == 1) {
        // no args
        engine = new QwirkleGameEngine();
    } else {
        unsigned int seed = 0;
        try {
            seed = std::stoi(argv[1]);
            engine = new QwirkleGameEngine(seed);
        } catch (const std::exception &ex) {
            std::cout << "Invalid seed given" << std::endl;
            QwirkleGameEngine::quit();
        }

    }
    if (engine != nullptr) {
        engine->start();
    }

    delete engine;
    return EXIT_SUCCESS;
}
