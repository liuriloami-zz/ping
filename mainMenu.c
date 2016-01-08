#ifndef MAINMENU_C
#define MAINMENU_C

#include "mainMenu.h"

/////////////////////////////////////////////////////////////
//Draw the main menu in the screen.
/////////////////////////////////////////////////////////////

void initMainMenu() {
    while (quit==0)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type) {
                   case SDL_QUIT:
                quit = 1;
                canRun = leave;
                break;

                   case SDL_MOUSEBUTTONDOWN:
                if (event.motion.x >= 82 && event.motion.x <= 200 && event.motion.y >= 86 && event.motion.y <= 140) {
                    canRun = onePlayer; //1 player
                    quit = 1;
                }

                if (event.motion.x >= 586 && event.motion.x <= 705 && event.motion.y >= 86 && event.motion.y <= 140) {
                    canRun = twoPlayers; //2 players
                    quit = 1;
                }

                if (event.motion.x >= 82 && event.motion.x <= 200 && event.motion.y >= 453 && event.motion.y <= 508) {
                    canRun = highScore; //high score
                    quit = 1;
                }

                if (event.motion.x >= 336 && event.motion.x <= 453 && event.motion.y >= 521 && event.motion.y <= 577) {
                    canRun = credits; //credits
                    quit = 1;
                }

                if (event.motion.x >= 586 && event.motion.x <= 702 && event.motion.y >= 453 && event.motion.y <= 508) {
                    canRun = leave; //leave
                    quit = 1;
                }
                break;
            }
        }
        plotImage (0, 0, menu, screen);
        SDL_Flip(screen);
        SDL_Delay(5);
    }
}

#endif
