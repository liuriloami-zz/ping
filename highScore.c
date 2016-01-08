#ifndef HIGHSCORE_C
#define HIGHSCORE_C

#include "highscore.h"

/////////////////////////////////////////////////////////////
//To draw the highScore in the screen.
/////////////////////////////////////////////////////////////

void initHighScore() {

    while (quit==0)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || event.type == SDL_MOUSEBUTTONDOWN) {
                quit = 1;
                canRun = mainMenu;
            }
        }


        plotImage (0, 0, highscore, screen);

        for (i = 0; i < 5; i++) {
            sprintf(printScore, "%d", highScoreA[i]);
            text = TTF_RenderText_Solid(font, printScore, textColor);
            plotImage(300, 200+50*i, text, screen);

            sprintf(printScore, "X", highScoreA[i]);
            text = TTF_RenderText_Solid(font, printScore, textColor);
            plotImage(400, 200+50*i, text, screen);

            sprintf(printScore, "%d", highScoreB[i]);
            text = TTF_RenderText_Solid(font, printScore, textColor);
            plotImage(500, 200+50*i, text, screen);
        }

        SDL_Flip(screen);
        SDL_Delay(5);
    }
}





#endif
