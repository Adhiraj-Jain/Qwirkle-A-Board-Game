
#ifndef ASSIGN1_TILECODES_H
#define ASSIGN1_TILECODES_H




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

#define COMMAND_REGEX "^(save .+|place [ROYGBP][1-6] at [A-F][0-5]|replace [ROYGBP][1-6])$"

#endif // ASSIGN1_TILECODES_H
