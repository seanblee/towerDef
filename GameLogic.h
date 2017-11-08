//
// Created by Alice Santilli on 2017-11-08.
//

#ifndef MADAWASKA_GAMELOGIC_H
#define MADAWASKA_GAMELOGIC_H

#include <string>
#include "Wave.h"

using namespace std;

class GameLogic {

private:
    int gameState;
    int currentWaveNum;


public:
    GameLogic(int){};
    void setCurrentWave(int);
    int getGameState();

};



#endif //MADAWASKA_GAMELOGIC_H
