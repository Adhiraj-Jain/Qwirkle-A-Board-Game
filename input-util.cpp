#include "input-util.h"
#include <iostream>
#include <limits>

int input_util::getIntInput() {
    int input = -1;
    bool valid = false;
    while (!valid) {
        std::cout << "> " << std::flush;
        std::cin >> input;
        // if the std hasn't struggled dumping the int value
        if (std::cin.good()) {
            valid = true;
        } else {
            //something went wrong, we reset the buffer's state to good
            std::cin.clear();
            //and empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Given input is not a number" << std::endl;
        }
    }
    return input;
}

int input_util::getOptionUserInput(int max) {
    int input = -1;
    bool valid = false;
    while (!valid) {
        input = getIntInput();
        if (input < 1 || input > max)
            std::cout << "Input must be between 1 and " << max << std::endl;
        else valid = true;
    }
    return input;
}

std::string input_util::getStringInput(std::regex regex) {
    std::string input;
    bool valid = false;
    while (!valid) {
        std::cout << "> " << std::flush;
        std::cin >> input;
        // check if input matches given regex
        bool found = std::regex_search(input, regex);
        if (!found) {
            std::cout << "Invalid input" << std::endl;
        } else valid = true;
    }
    return input;
}