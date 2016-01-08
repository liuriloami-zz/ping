#ifndef MAIN_C
#define MAIN_C

#include "firstLayer.h"
#include "secondLayer.h"
#include "twoPlayers.h"
#include "onePlayer.h"
#include "mainMenu.h"
#include "credits.h"
#include "highScore.h"
#include "winner.h"

/////////////////////////////////////////////////////////////
//This main function is responsible for keeping the game running a loop and select the current screen.
/////////////////////////////////////////////////////////////

int main(int argc, char **argv){
    initEverything();
    
    loadScoreFile();
    canRun = mainMenu;
    while (canRun != leave) {
        quit = 0;
        switch (canRun) {
               case mainMenu:
            initMainMenu();
            break;

               case highScore:
            initHighScore();
            break;

               case credits:
            initCredits();
            break;

               case onePlayer:
            initOnePlayer();
            break;

               case twoPlayers:
            initTwoPlayers();
            break;

               case showWinner:
            InitWinner();
            break;
        }
    }
    return 0;
}

#endif

