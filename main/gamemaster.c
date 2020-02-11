#include <stdio.h>
#include <gb/gb.h>
#include <gb/font.h>
#include "../Sprites/windowmap.c"
#include <gb/drawing.h>

UINT16 laststarttime;
font_t loadedFont;

void drawscore();

void loadFont() {
    font_t min_font;
    
    font_init();
    min_font = font_load(font_min);
    font_set(min_font);
	loadedFont = min_font;
}

void setupWindow() {
	set_win_tiles(0, 0, 5, 1, windowmapstart);
	move_win(10, 127);
}

void startGame() {
    waitpad(J_START);
	delay(300);
    set_win_tiles(0, 0, 5, 1, windowmapscore);
	laststarttime = sys_time;
}

// Counter does not work on every game start. Try to reload the game
void drawscore(){
	UINT8 score[1] = {12};
	UINT8 digitmap[1];
	INT16 time;
	INT8 numdigitsdrawn = 0;
	
	// dont want to redraw more than once per half second
	if(sys_time % 30 != 0){
		return;
	}

	// Increase score count per sec
	time = (sys_time-laststarttime)/30;

	while (time != 0) {
		digitmap[0] = time % 10 + 2;
		// draw next lowest digit
		set_win_tiles(18 - numdigitsdrawn, 0, 1, 1, digitmap);
		numdigitsdrawn++;
		time = time/10;
	}
}
