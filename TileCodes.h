#ifndef ASSIGN2_TILECODES_H
#define ASSIGN2_TILECODES_H

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

// Assumes a board of 26x26
#define COMMAND_REGEX "^(save .+|place [ROYGBP][1-6] at [A-Z](2[0-5]|[0-9]|1[0-9])|replace [ROYGBP][1-6])$"

#endif // ASSIGN2_TILECODES_H
