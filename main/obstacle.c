#include <stdio.h>
#include <gb/gb.h>
#include "utils.h"
#include "../main.h"


struct Gameobstacle {
    UBYTE spriteId[1];
    UINT8 x;
    UINT8 y;
    UINT8 height;
    UINT8 width; 
};