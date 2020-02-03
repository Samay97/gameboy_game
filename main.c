#include <stdio.h>
#include <gb/gb.h>
#include "sprites/smiler.h"

UINT8 currentSpriteIndex = 0;

void showCharacter() {
    set_sprite_data(0, 2, TileLabel);
    set_sprite_tile(0 ,0);
    move_sprite(0, 80, 80);
    SHOW_SPRITES;
}

void main() {
    while (1)
    {
        if (currentSpriteIndex == 0) {
            currentSpriteIndex = 1;
        } else {
            currentSpriteIndex = 0;
        }
        set_sprite_tile(0, currentSpriteIndex);
        delay(500);
    }
    
    while(1) {
        switch(joypad()) {
            case J_LEFT:
                printf("Left!\n");
                delay(100);
                break;
            case J_RIGHT:
                printf("Right!\n");
                delay(100);
                break;
            case J_UP:
                printf("Up!\n");
                delay(100);
                break;
            case J_DOWN:
                printf("Down!\n");
                delay(100);
                break;
            case J_START:
                printf("Start!\n");
                delay(100);
                break;
            case J_SELECT:
                printf("Select!\n");
                delay(100);
                break;
            case J_A:
                printf("A!\n");
                delay(100);
                break;
            case J_B:
                printf("B!\n");
                delay(100);
                break;
        }
    }
}