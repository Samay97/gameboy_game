#include <stdio.h>
#include <gb/gb.h>
#include "Sprites/background1.c"
#include "Sprites/backgroundtiles.c"
#include "Sprites/background2.c"


INT8 playerlocation[2]; // stores two INT8 x and y postion of player
BYTE isJumping;
UINT8 gravity = -2;
UINT8 currentspeedY;
UINT8 floorY = 100;

void performantDelay(UINT8 numloops) {
    UINT8 i;
    for(i = 0; i < numloops; i++) {
        // Wait until screen draw
        wait_vbl_done();
    }
}

INT8 wouldHitSurface(UINT8 projectedYPosition) {
    if(projectedYPosition >= floorY){
        return floorY;
    }
    return -1;
}

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

void main() {
    set_bkg_data(0, 5, backgroundtiles);
    set_bkg_tiles(0, 0, 32, 19, backgroundmap1);
    
    set_bkg_tiles(0, 14, 32, 19, backgroundmap2);

    set_sprite_data(0, 8, Smiler);
    set_sprite_tile(0, 0);

    playerlocation[0] = 10;
    playerlocation[1] = floorY;
    isJumping = 0;
    // Init Player location
    move_sprite(0, playerlocation[0], playerlocation[1]);

    DISPLAY_ON;
    SHOW_SPRITES;


    while(1) {
        scroll_bkg(1, 0);

        if((joypad() & J_A) || isJumping == 1){
            jumpPlayer(0,playerlocation);
        }

        if(joypad() & J_LEFT){
            playerlocation[0] = playerlocation[0] - 2;
            move_sprite(0,playerlocation[0],playerlocation[1]);
        }

        if(joypad() & J_RIGHT){
            playerlocation[0] = playerlocation[0] + 2;
            move_sprite(0,playerlocation[0],playerlocation[1]);
        }

        performantDelay(5);
    }
}