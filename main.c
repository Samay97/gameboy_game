#include <stdio.h>
#include <gb/gb.h>
#include "main.h"
#include "main/player.c"
#include "main/utils.h"
<<<<<<< HEAD
#include "main/gamemaster.c"
=======
#include "main/obstacle.c"
>>>>>>> Collision
// Sprites
#include "sprites/flamingo.c"
#include "Sprites/background1.c"
#include "Sprites/backgroundtiles.c"
#include "Sprites/background2.c"
#include "Sprites/Busch.c"

struct Gameobstacle obstacle;
struct GameCharacter player;
UBYTE spriteSize = 8;
UINT8 Speed = 5;
UINT16 SpeedIncrease = 0;

// Set global varibales
UINT8 floorY = 88;
UINT8 gravity = -2;

void setupGameobstacle(){
    obstacle.x = 140;
    obstacle.y = 96;
    obstacle.width = 16;
    obstacle.height = 16;    

    // load sprites for Busch
    set_sprite_tile(5, 5);
    obstacle.spriteId[0]=5;

}

void moveBusch(){

    move_sprite(obstacle.spriteId[0], obstacle.x, obstacle.y);  

}

void IncreaseSpeed(){
    SpeedIncrease++;
    if(SpeedIncrease >= 100){
        SpeedIncrease = 0;
        Speed++;
    }
}

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
 
UBYTE checkcollisions(struct GameCharacter* one, struct Gameobstacle* two){
    return (one->x >= two->x && one->x <= two->x + two->width) && (one->y >= two->y && one->y <= two->y + two->height) || (two->x >= one->x && two->x <= one->x + one->width) && (two->y >= one->y && two->y <= one->y + one->height);
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

<<<<<<< HEAD
    
    SHOW_WIN;
    SHOW_BKG;
    SHOW_SPRITES;

    DISPLAY_ON;

    startGame();

    while(1) {
        scroll_bkg(1, 0);
        drawscore();
=======
    // Busch
    set_sprite_data(5, 1, busch);
    setupGameobstacle();


    DISPLAY_ON;
    SHOW_BKG;
    SHOW_SPRITES;


    while(!checkcollisions(&player, &obstacle)) {
        scroll_bkg(3, 0);
>>>>>>> Collision
        
        if((joypad() & J_A) || player.isJumping == 1){
            jumpPlayer(&player);
        }

        if(joypad() & J_LEFT){
            movePlayerLeft(&player);
        }

        if(joypad() & J_RIGHT){
            movePlayerRight(&player);
        }

        obstacle.x -= Speed;

        moveBusch(obstacle.x , obstacle.y);
        IncreaseSpeed();

        performantDelay(5);
    }

}
