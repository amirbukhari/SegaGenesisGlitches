/*
 * main.c
 *
 *  Created on: Feb 19, 2017
 *      Author: Amir_2
 */
#include <genesis.h>
static void showIntroScreen();
int main()
{
   // VDP_drawText("INHALANTS", 16, 12);


	showIntroScreen();
    while(1)
    {
        //read input
        //move sprite
        //update score
        //draw current screen (logo, start screen, settings, game, gameover, credits...)

        //wait for screen refresh
        VDP_waitVSync();
    }
    return (0);
}

static void showIntroScreen()
{

    	u16 col = 0xEEE;
    	// set text color to black
    	VDP_setPaletteColor(15, 0x333);
    	// display test string
    	VDP_drawText("INHALANTS", 10, 10);
    	VDP_drawText("Press START to begin", 10, 14);

    	// fade text color to white
    	VDP_fadeIn(15, 15, &col, 13, FALSE);
    	// wait for Start button pressed
    	JOY_waitPress(JOY_1, BUTTON_START);
    	// fade text
    	VDP_fadeOut(15, 15, 30, FALSE);
    	// clear text
    	VDP_clearPlan(PLAN_A, TRUE);

    	// reset text color to white
    	VDP_setPaletteColor(15, 0xEEE);
}
