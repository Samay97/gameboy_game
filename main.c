#include <stdio.h>
#include <gb/gb.h>
#include "main.h"
#include "main/player.c"
#include "main/utils.h"
#include "main/gamemaster.c"
// Sprites
#include "sprites/flamingo.c"
#include "Sprites/background1.c"
#include "Sprites/backgroundtiles.c"
#include "Sprites/background2.c"

struct GameCharacter player;
UBYTE spriteSize = 8;

// Set global varibales
UINT8 floorY = 88;
UINT8 gravity = -2;

void setupGameCharacter() {
    player.x = 10;
    player.y = floorY;
    player.width = 16;
    player.height = 16;

    // loadsprites
    set_sprite_tile(0, 0);
    player.spriteId[0] = 0;
    set_sprite_tile(1, 1);
    player.spriteId[1] = 1;
    set_sprite_tile(2, 2);
    player.spriteId[2] = 2;
    set_sprite_tile(3, 3);
    player.spriteId[3] = 3;

    // Init Player location
    moveGameCharacter(&player, player.x, player.y);
}

void setupBackground() {
    // Fonts blocking from 0-37
    set_bkg_data(38, 5, backgroundtiles);
    set_bkg_tiles(0, 0, 32, 19, backgroundmap1);    
    set_bkg_tiles(0, 14, 32, 19, backgroundmap2);
}
 
void main() {
    //load font
    loadFont();
    // Background
    setupBackground();
    // Window
    setupWindow();

    // Player
    set_sprite_data(0, 4, Flamingo);
    setupGameCharacter();
    player.isJumping = 0;

    
    SHOW_WIN;
    SHOW_BKG;
    SHOW_SPRITES;

    DISPLAY_ON;

    startGame();

    while(1) {
        scroll_bkg(1, 0);
        drawscore();
        
        if((joypad() & J_A) || player.isJumping == 1){
            jumpPlayer(&player);
        }

        if(joypad() & J_LEFT){
            movePlayerLeft(&player);
        }

        if(joypad() & J_RIGHT){
            movePlayerRight(&player);
        }

        performantDelay(5);
    }
}