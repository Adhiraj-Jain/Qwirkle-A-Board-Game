#ifndef ASSIGN2_CONSTANTS_H
#define ASSIGN2_CONSTANTS_H

#include "typedefs.h"

#define NEW_GAME 1
#define LOAD_GAME 2
#define CREDITS 3
#define EXPANSION_BOARD 4
#define MULTIPLE_PLAYERS 5
#define COLOUR 6
#define QUIT 7
#define EXPANSION_BOARD_STR "EXPAND"
#define MULTIPLE_PLAYERS_STR "MULTIPLAYER"
#define COLOURS_STR "COLOURS"

//Color codes
#define RESET   "\033[0m"
#define RED_C     "\033[31m"      /* Red */
#define GREEN_C   "\033[32m"      /* Green */
#define YELLOW_C "\033[33m"      /* Yellow */
#define BLUE_C    "\033[38;5;21m"      /* Blue */
#define MAGENTA_C "\033[35m"
#define ORANGE_C    "\033[38;5;202m"      /* Cyan */
#define WHITE_C   "\033[37m"



// Colours

#define COLOURS_SIZE 6
#define RED    'R'
#define ORANGE 'O'
#define YELLOW 'Y'
#define GREEN  'G'
#define BLUE   'B'
#define PURPLE 'P'


// Shapes

#define SHAPES_SIZE 6
#define CIRCLE  1
#define STAR_4  2
#define DIAMOND 3
#define SQUARE  4
#define STAR_6  5
#define CLOVER  6

// Assumes a board of 26x26. This regex represents all possible commands supported by the program
#define COMMAND_REGEX "^(save .+|place [ROYGBP][1-6] at [A-Z](2[0-5]|[0-9]|1[0-9])|replace [ROYGBP][1-6])$"
#define MAX_PLAYERS 2
#define HAND_SIZE 6
#define TEAM_SIZE 4

#define MAX_BOARD_SIZE 26
#define QWIRKLE_LENGTH 6
#define QWIRKLE_POINTS 6

namespace constants {
    // const static is a hint to the compiler to define these only once.
    const static Colour COLOURS[COLOURS_SIZE] = { RED, ORANGE, YELLOW, GREEN,
                                                 BLUE, PURPLE };
    const static Shape SHAPES[SHAPES_SIZE] = { CIRCLE, STAR_4, DIAMOND, SQUARE,
                                              STAR_6, CLOVER };
}

#endif // ASSIGN2_CONSTANTS_H
