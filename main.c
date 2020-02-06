#include <stdio.h>
#include <gb/gb.h>
#include "Sprites/background1.c"
#include "Sprites/backgroundtiles.c"
#include "Sprites/background2.c"


void main() {
            
    set_bkg_data(0, 5, backgroundtiles);
    set_bkg_tiles(0, 0, 32, 19, backgroundmap1);
    
    set_bkg_tiles(0, 14, 32, 19, backgroundmap2);

    SHOW_BKG;
    DISPLAY_ON;
    
    while(1)
    {    
        scroll_bkg(1, 0);
           
        delay(20);

    }
}