#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

Move parse_input(const char *line) {
    if (!line || strlen(line) == 0) return MOVE_INVALID;
    char ch = line[0];
    ch = (char)toupper((unsigned char)ch);
    switch (ch) {
        case 'W': return MOVE_UP;
        case 'A': return MOVE_LEFT;
        case 'S': return MOVE_DOWN;
        case 'D': return MOVE_RIGHT;
        default:  return MOVE_INVALID;
    }
}

Move read_move_from_stdin(void) {
    char buf[64];
    if (!fgets(buf, sizeof(buf), stdin)) {
        return MOVE_INVALID;
    }
    return parse_input(buf);
}