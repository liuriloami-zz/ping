#ifndef SECONDLAYER_C
#define SECONDLAYER_C

#include "secondLayer.h"


//Functions 

//For when a point is scored.
void initBallStats() {
    ballvx = 2*pow(-1,rand()%2);
    ballvy = (rand()%2 - 1);
    ballx = ballX0;
    bally = ballY0;
    for (i=0; i<ROBOT_PATH_SIZE; i++) {
        robotx[i] = ballX0;
        roboty[i] = H_MIN+20;
    }
}

/////////////////////////////////////////////////////////////
//To draw the background and the score (two Players).
/////////////////////////////////////////////////////////////

void plotStuff(){
    plotImage (0, 0, background, screen);
    if (WITH_ROBOT == 1) {
        for (i = 0; i < ROBOT_PATH_SIZE; i++)
            plotImage ((int)robotx[i]-10, (int)roboty[i]-10, robot, screen);
    }

    sprintf(printScore, "%d", pointsLeft);
    text = TTF_RenderText_Solid(font, printScore, textColor);
    plotImage(WIDTH/2 - 200, 40, text, screen);

    sprintf(printScore, "%d", pointsRight);
    text = TTF_RenderText_Solid(font, printScore, textColor);
    plotImage(WIDTH/2 + 200, 40, text, screen);
    plotImage (xLeft, yLeft, player, screen);
    plotImage (xRight, yRight, player, screen);
    plotImage (ballx-15, bally+15, ball, screen);
}     

/////////////////////////////////////////////////////////////
//To draw the background and the score (one Player).
/////////////////////////////////////////////////////////////

void plotStuff2(){
    plotImage (0, 0, background, screen);
    if (WITH_ROBOT == 1) {
        for (i = 0; i < ROBOT_PATH_SIZE; i++)
            plotImage ((int)robotx[i]-10, (int)roboty[i]-10, robot, screen);
    }

    sprintf(printScore, "%d", pointsLeft);
    text = TTF_RenderText_Solid(font, printScore, textColor);
    plotImage(WIDTH/2 - 200, 40, text, screen);

    sprintf(printScore, "%d", pointsRight);
    text = TTF_RenderText_Solid(font, printScore, textColor);
    plotImage(WIDTH/2 + 200, 40, text, screen);
    plotImage (xLeft, yLeft, player, screen);
    plotImage (xRight, yRight, player2, screen);
    plotImage (ballx-15, bally-15, ball, screen);
}   

/////////////////////////////////////////////////////////////
//Initializes images, score, font and sound.
/////////////////////////////////////////////////////////////

void initEverything(){
    if ((scoreFile = fopen("highScore.wtf","r")) != NULL) {
        for (i = 0; i < 5; i++)
            fscanf (scoreFile, "%d %d", &highScoreA[i], &highScoreB[i]);
        fclose(scoreFile);
    } else
        for (i = 0; i < 5; i++)
            highScoreA[i] = highScoreB[i] = 0;
    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_FULLSCREEN);
    SDL_WM_SetCaption("Ping", NULL);
    background = loadImage("images/gameField.png");
    player = loadImage("images/player.jpg");
    ball = loadImage("images/ball.png");
    menu = loadImage("images/mainMenu.jpg");
    robot = loadImage("images/robot.png");
    credit = loadImage("images/credits.jpg");
    highscore = loadImage("images/Highscores.jpg");
    font = TTF_OpenFont("Font/font.ttf", 30);
    player2 = loadImage("images/player2.JPG");
    
    Mix_OpenAudio (22050, AUDIO_S8, 1, 1024);
    boing = Mix_LoadWAV("sound/boing.wav");
    losesound = Mix_LoadWAV("sound/lose.wav");
    shallnotpass = Mix_LoadWAV("sound/shallnotpass.wav");
    
}

/////////////////////////////////////////////////////////////
//To free memory previously used
/////////////////////////////////////////////////////////////

void closeSDL(){
    SDL_FreeSurface(ball);
    SDL_FreeSurface(player);
    SDL_FreeSurface(background);
    Mix_FreeChunk(boing);
    Mix_FreeChunk(losesound);
    Mix_FreeChunk(shallnotpass);
    Mix_CloseAudio();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

SDL_Surface *loadImage(char* filename){
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename);
    if (loadedImage!=NULL){
        optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    return optimizedImage;
}

/////////////////////////////////////////////////////////////
//To draw a surface in the screen.
/////////////////////////////////////////////////////////////

void plotImage(int x, int y, SDL_Surface* origem, SDL_Surface* destino){
    SDL_Rect borda;
    borda.x = x;
    borda.y = y;
    SDL_BlitSurface(origem, NULL, destino, &borda);
}

/////////////////////////////////////////////////////////////
//To load de score from the file.
/////////////////////////////////////////////////////////////

void loadScoreFile() {
    if ((scoreFile = fopen("highscore.wtf", "r")) == NULL) {
        for (i = 0; i < 5; i++)
            highScoreA[i] = highScoreB[i] = 0;
    } else {
        for (i = 0; i < 5; i++)
            fscanf(scoreFile, "%d %d", &highScoreA[i], &highScoreB[i]);
        fclose(scoreFile);
    }
}


#endif
