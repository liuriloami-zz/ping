#ifndef FIRSTLAYER_C
#define FIRSTLAYER_C

#include "firstLayer.h"

/////////////////////////////////////////////////////////////
//SDL variables
/////////////////////////////////////////////////////////////

SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *player = NULL;
SDL_Surface *ball = NULL;
SDL_Surface *menu = NULL;
SDL_Surface *robot = NULL;
SDL_Surface *credit = NULL;
SDL_Surface *highscore = NULL;
SDL_Surface *score[5] = {NULL,NULL,NULL,NULL,NULL};
SDL_Surface *text = NULL;
SDL_Surface *player2 = NULL;

SDL_Event event;
Uint8 *keystates = SDL_GetKeyState(NULL);
SDL_Color textColor = {255, 255, 255};
TTF_Font *font = NULL;

Mix_Chunk *boing = NULL;
Mix_Chunk *losesound = NULL;
Mix_Chunk *shallnotpass = NULL;


/////////////////////////////////////////////////////////////
//Other variables
/////////////////////////////////////////////////////////////

int quit = 0;
int xLeft = xLeftINI;
int yLeft = yLeftINI;
int xRight = xRightINI; 
int yRight = yRightINI;
int gravity = GRAVITY;
int ballx, bally;
int i, j, k;
int pointsLeft, pointsRight;
int highScoreA[5], highScoreB[5], act, t1[2], t2[2];
int winner;
int gameType;
int pause;

double ballvx, ballvy;
double tmp, aux;
double robotx[ROBOT_PATH_SIZE];
double roboty[ROBOT_PATH_SIZE];
double robotvx = 0;
double robotvy = 0;
double compv;

type_situations canRun = twoPlayers;

FILE *scoreFile;

char printScore[10];

#endif
