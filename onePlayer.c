#ifndef ONEPLAYERS_C
#define ONEPLAYERS_C

#include "onePlayer.h"

/////////////////////////////////////////////////////////////
//Play against an artificial intelligence
/////////////////////////////////////////////////////////////

void initOnePlayer() {

    //Some initial values
    compv = 0.0;
    pause = 0;
    initBallStats();
    srand(time(NULL));
    pointsLeft = pointsRight = 0;
    act = -1;

    //Main loop
    while (quit==0)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || event.type == SDL_MOUSEBUTTONDOWN) {
                quit = 1;
                canRun = mainMenu;
            }
            if (keystates[SDLK_p])
                pause = pause==1?0:1;
        }

        //Limiting the movement of the players
        if (yRight>=H_MAX-SIZEPLAYER) {
            yRight=H_MAX-SIZEPLAYER-1;
            compv *= -1;
        }
        if (yLeft>=H_MAX-SIZEPLAYER)
            yLeft=H_MAX-SIZEPLAYER;
            
        if (yRight<=H_MIN-SIZEPLAYER/2) {
            yRight=H_MIN-SIZEPLAYER/2+1;
            compv *= -1;
        }

        if (yLeft<=H_MIN-SIZEPLAYER/2)
            yLeft=H_MIN-SIZEPLAYER/2;

        
        if (pause == 0) {

            //Movement of the players
            if (keystates[SDLK_s])
            {
                yLeft+=6;
            }

            if (keystates[SDLK_w])
            {
                yLeft-=6;
            }
            
            if(ballx > WIDTH/2)
                if (bally > yRight)
                    compv+=COMP;
            else
                compv-=COMP;

            if (compv > 6) 
                compv = 6;
            else if (compv < -6) 
                compv = -6;
            
            yRight += (int)compv;

            //Physics of the ball ang limitation
            ballvy += gravity;
            bally +=(int)ballvy;
            ballx +=(int)ballvx;

            if (bally>=H_MAX-SIZEBALL) {
                ballvy *= -1.1;
                bally = H_MAX-SIZEBALL-1;
            }

            if (bally<=H_MIN-SIZEBALL) {
                ballvy *= -1.1;
                bally = H_MIN-SIZEBALL+1;
            }

            //Point of the left player
            if (ballx>=WIDTH-SIZEBALL){
                Mix_PlayChannel(-1, losesound, 0);
                initBallStats();
                SDL_Delay(2000);
                pointsLeft++;
                if (pointsLeft == 5) {
                    winner = 0;
                    quit = 1;
                    canRun = showWinner;
                    gameType = 0;
                    Mix_PlayChannel(-1, shallnotpass, 0);
                }
            }
            
            //Point of the right player
            if (ballx<=0){
                Mix_PlayChannel(-1, losesound, 0);
                initBallStats();
                SDL_Delay(2000);
                pointsRight++;
                if (pointsRight == 5) {
                    winner = 1;
                    gameType = 0;
                    quit = 1;
                    canRun = showWinner;
                    Mix_PlayChannel(-1, shallnotpass, 0);
                }
            }

            // Colision with the players.
            if (ballx <= xLeft+31 && bally >= yLeft-45 && bally <= yLeft+68)
            {
                Mix_PlayChannel(-1, boing, 0);
                ballvx *= -1.1;
                while (ballx <= xLeft+31)
                    ballx++;
                if (keystates[SDLK_s])
                    ballvy+=1;
                if (keystates[SDLK_w])
                    ballvy-=1;
            }

            if (ballx >= xRight-15 && bally >= yRight-45 && bally <= yRight+68){
                Mix_PlayChannel(-1, boing, 0);
                ballvx *= -1.1;
                while(ballx >= xRight-15)
                    ballx --;
                if (keystates[SDLK_l])
                    ballvy+=1;
                if (keystates[SDLK_o])
                    ballvy-=1;
            }
        }

        //For the tests with a orbit "robot" (to activate, use #define WITH_ROBOT 1)
        tmp = atan2(bally-roboty[ROBOT_PATH_SIZE-1], ballx-robotx[ROBOT_PATH_SIZE-1]);
        robotvx += 0.5*cos(tmp);
        robotvy += 0.5*sin(tmp);

        for (i = 0; i < ROBOT_PATH_SIZE-1; i++) {
            robotx[i] = robotx[i+1];
            roboty[i] = roboty[i+1];
        }

        robotx[ROBOT_PATH_SIZE-1] += robotvx;
        roboty[ROBOT_PATH_SIZE-1] += robotvy;

        
        if (robotvx > 10) robotvx = 10;
        if (robotvy > 10) robotvy = 10;


        //Limit the ball speed
        if (ballvx > 4) ballvx = 4;
        if (ballvy > 4) ballvy = 4;

        plotStuff2();
        SDL_Flip(screen);
        SDL_Delay(5);
    }

}













#endif
