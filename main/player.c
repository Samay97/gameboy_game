#include <stdio.h>
#include <gb/gb.h>
#include "utils.c"
#include "../main.h"

INT8 playerlocation[2]; // stores two INT8 x and y postion of player
BYTE isJumping;
UINT8 currentspeedY;

void movePlayerLeft() {
    playerlocation[0] = playerlocation[0] - 2;
    move_sprite(0, playerlocation[0], playerlocation[1]);
}

void movePlayerRight() {
    playerlocation[0] = playerlocation[0] + 2;
    move_sprite(0, playerlocation[0], playerlocation[1]);
}

void jumpPlayer(UINT8 spriteid, UINT8 spritelocation[2]){
    UINT8 possibleSurfaceY;

    if(isJumping == 0){
        isJumping = 1;
        currentspeedY = 10;
    }

    // work out current speed - effect of gravities accelleration down
    currentspeedY = currentspeedY + gravity;    

    spritelocation[1] = spritelocation[1] - currentspeedY;
    possibleSurfaceY = wouldHitSurface(spritelocation[1]);
    if(possibleSurfaceY != -1){
        isJumping = 0;
        move_sprite(spriteid,spritelocation[0], possibleSurfaceY);
    }
    else{
        move_sprite(spriteid,spritelocation[0], spritelocation[1]);
    }
}