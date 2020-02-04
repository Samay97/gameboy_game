#include <stdio.h>
#include <gb/gb.h>
#include "main.h"
#include "main/player.c"
#include "main/utils.h"
// Sprites
#include "sprites/smiler.c"
#include "Sprites/background1.c"
#include "Sprites/backgroundtiles.c"
#include "Sprites/background2.c"

// Set global varibales
UINT8 floorY = 100;
UINT8 gravity = -2;

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