#include <stdio.h>
#include <gb/gb.h>
#include "utils.h"
#include "../main.h"

void performantDelay(UINT8 numloops) {
    UINT8 i;
    for(i = 0; i < numloops; i++) {
        // Wait until screen draw
        wait_vbl_done();
    }
}

UINT8 wouldHitSurface(UINT8 projectedYPosition) {
    if(projectedYPosition >= floorY){
        return floorY;
    }
    return -1;
}
