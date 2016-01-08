#ifndef WINNER_C
#define WINNER_C

#include "winner.h"

/////////////////////////////////////////////////////////////
//To draw in the screen who is the winner and to save the highScore in the file.
/////////////////////////////////////////////////////////////

void InitWinner() {

    scoreFile = fopen("highScore.wtf","w");

    if (gameType == 0) {
        
        for (i = 0; i < 5; i++)
            if (pointsLeft-pointsRight > highScoreA[i]-highScoreB[i] || (pointsLeft-pointsRight == highScoreA[i]-highScoreB[i] && pointsLeft > highScoreA[i])) {
            t1[0] = highScoreA[i];
            t2[0] = highScoreB[i];
            for (j = i+1; j < 5; j++) {
                t1[1] = highScoreA[j];
                t2[1] = highScoreB[j];
                highScoreA[j] = t1[0];
                highScoreB[j] = t2[0];
                t1[0] = t1[1];
                t2[0] = t2[1];
            }
            highScoreA[i] = pointsLeft;
            highScoreB[i] = pointsRight;
            i = 5;
        }
        
    }

    for (i = 0; i < 5; i++)
        fprintf (scoreFile, "%d %d\n", highScoreA[i], highScoreB[i]);
        
    fclose(scoreFile);

    if (gameType == 0)
        if (winner == 0)
            sprintf(printScore, "HUMAN PLAYER WINS", pointsLeft);
    else
        sprintf(printScore, "COMPUTER PLAYER WINS", pointsLeft);
    else
        if (winner == 0)
            sprintf(printScore, "LEFT PLAYER WINS", pointsLeft);
    else
        sprintf(printScore, "RIGHT PLAYER WINS", pointsLeft);

    text = TTF_RenderText_Solid(font, printScore, textColor);
    plotImage(WIDTH/2 - text->w/2, 10, text, screen);

    while (quit==0)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || event.type == SDL_MOUSEBUTTONDOWN) {
                quit = 1;
                canRun = mainMenu;
            }
        }
        SDL_Flip(screen);
        SDL_Delay(5);
    }
}





#endif
