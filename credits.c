#ifndef CREDITS_C
#define CREDITS_C

#include "credits.h"

/////////////////////////////////////////////////////////////
//To draw the credits in the screen.
/////////////////////////////////////////////////////////////

void initCredits() {
    while (quit==0)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || event.type == SDL_MOUSEBUTTONDOWN) {
                quit = 1;
                canRun = mainMenu;
            }
        }
        plotImage (0, 0, credit, screen);
        SDL_Flip(screen);
        SDL_Delay(5);
    }
}





#endif
