#ifndef FIRSTLAYER_H
#define FIRSTLAYER_H

//Includes
#include <stdio.h>
#include <math.h>
#include <string>
#include "SDL\SDL.h"
#include "SDL\SDL_image.h"
#include "SDL\SDL_ttf.h"
#include "SDL\SDL_mixer.h"


//Defines
#define xLeftINI 40
#define yLeftINI 270
#define xRightINI 740
#define yRightINI 270
#define GRAVITY 0
#define ballX0 WIDTH/2
#define ballY0 HEIGHT/2
#define SIZEPLAYER 83
#define SIZEBALL 30
#define H_MAX HEIGHT-45
#define H_MIN 130
#define WITH_ROBOT 0
#define MLP_Input 6
#define MLP_Hidden 18
#define MLP_Output 1
#define WIDTH 800
#define HEIGHT 600
#define BPP 32
#define ROBOT_PATH_SIZE 25
#define COMP 0.5

/////////////////////////////////////////////////////////////
//Typedef - Enum
/////////////////////////////////////////////////////////////

enum situations {leave, mainMenu, highScore, credits, onePlayer, twoPlayers, iaTraining, showWinner};
typedef enum situations type_situations;

/////////////////////////////////////////////////////////////
//Prototype - variables
/////////////////////////////////////////////////////////////

extern SDL_Surface *screen;
extern SDL_Surface *background;
extern SDL_Surface *player;
extern SDL_Surface *ball;
extern SDL_Surface *menu;
extern SDL_Surface *robot;
extern SDL_Surface *credit;
extern SDL_Surface *highscore;
extern SDL_Surface *text;
extern SDL_Surface *player2;


extern TTF_Font *font;
extern SDL_Color textColor;
extern SDL_Event event;
extern Uint8 *keystates;


extern Mix_Chunk *boing;
extern Mix_Chunk *losesound;
extern Mix_Chunk *shallnotpass;


extern int quit;
extern int xLeft, yLeft, xRight, yRight;
extern int gravity;
extern int ballx, bally;
extern int i, j, k, act;
extern int pointsLeft, pointsRight;
extern int highScoreA[5], highScoreB[5], t1[2], t2[2];
extern int winner;
extern int gameType;
extern int pause;


extern double ballvx, ballvy;
extern double robotx[ROBOT_PATH_SIZE], robotvx;
extern double roboty[ROBOT_PATH_SIZE], robotvy;
extern double tmp;
extern double compv;

extern type_situations canRun;

extern FILE *scoreFile;

extern char printScore[10];



#endif
