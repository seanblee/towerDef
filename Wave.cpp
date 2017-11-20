//
// Created by Alice Santilli on 2017-11-08.
//

#include "Wave.h"

using namespace std;


Wave::Wave(int currentNum) {
    if (currentNum == 1) {
        cWave = 1;
        cHostileNum = 10;
        cHType = 1;
    }
    else if (currentNum == 2) {
        cWave = 2;
        cHostileNum = 20;
        cHType = 2;
    }
    else {
        cWave = 3;
        cHostileNum = 30;
        cHType = 3;
    }
}

int Wave::getWaveNumber() {
    return cWave;
}

int Wave::getHostileAmount() {
    return cHostileNum;
}

int Wave::getHostileType() {
    return cHType;
}