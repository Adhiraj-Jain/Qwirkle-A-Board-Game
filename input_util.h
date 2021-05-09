#ifndef ASSIGN2_INPUT_UTIL_H
#define ASSIGN2_INPUT_UTIL_H

#include <string>
#include <regex>
#include "typedefs.h"

namespace input_util {
    /**
     * Blocking function which asks a user for a number input within a range 1-max
     * @param max maximum int user can enter
     * @return
     */
    int getOptionUserInput(int max);

    /**
     * Blocking function which asks a user for a number input
     * @return number user entered
     */
    int getIntInput();

    /**
     * Blocking function to get string input from the user which much match the given regex
     * @param regex regex to check against
     * @return string input which matches regex
     */
    string getStringInput(const std::regex &regex, const string &error = "Invalid input");
}
#endif //ASSIGN2_INPUT_UTIL_H
