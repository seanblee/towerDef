//
// Created by Alice Santilli on 2017-11-08.
//


#include "Wave.h"
#include "GameLogic.h"

using namespace std;


GameLogic::GameLogic(int startwavenum) {
    currentWaveNum = startwavenum;
    Wave firstwave(startwavenum);
    gameState =  1;
}

void GameLogic::setCurrentWave(int cWaveNum) {
    currentWaveNum = cWaveNum;
}

int GameLogic::getGameState() {
    return gameState;
}


