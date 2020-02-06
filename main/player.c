#include <stdio.h>
#include <gb/gb.h>
#include "utils.c"
#include "../main.h"

struct GameCharacter {
    UBYTE spriteId[4];
    UINT8 x;
    UINT8 y;
    UINT8 height;
    UINT8 width; 
    BYTE isJumping;
    UINT8 currentspeedY;
};

void moveGameCharacter(struct GameCharacter* character, UINT8 x, UINT8 y) {
    move_sprite(character->spriteId[0], x, y);
    move_sprite(character->spriteId[1], x + spriteSize, y);
    move_sprite(character->spriteId[2], x, y + spriteSize);
    move_sprite(character->spriteId[3], x + spriteSize, y + spriteSize);
}

void movePlayerLeft(struct GameCharacter* player) {
    player->x = player->x - 2;
    moveGameCharacter(player, player->x, player->y);
}

void movePlayerRight(struct GameCharacter* player) {
    player->x = player->x + 2;
    moveGameCharacter(player, player->x, player->y);
}

void jumpPlayer(struct GameCharacter* player){
    UINT8 possibleSurfaceY;

    if(player->isJumping == 0){
        player->isJumping = 1;
        player->currentspeedY = 10;
    }

    // work out current speed - effect of gravities accelleration down
    player->currentspeedY = player->currentspeedY + gravity;    

    player->y = player->y - player->currentspeedY;
    possibleSurfaceY = wouldHitSurface(player->y);
    if(possibleSurfaceY != -1){
        player->isJumping = 0;
        moveGameCharacter(player, player->x, possibleSurfaceY);
    }
    else{
        moveGameCharacter(player, player->x, player->y);
    }
}