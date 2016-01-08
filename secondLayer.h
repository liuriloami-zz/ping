#ifndef SECONDLAYER_H
#define SECONDLAYER_H

#include "firstLayer.h"

/////////////////////////////////////////////////////////////
//Prototypes of the functions
/////////////////////////////////////////////////////////////

void initEverything();
void initBallStats();
void closeSDL();
SDL_Surface *loadImage(char* filename);
void plotImage(int x, int y, SDL_Surface* origem, SDL_Surface* destino);
double f(double x);
double df(double x);
void loadScoreFile();
void plotStuff();
void plotStuff2();

#endif
