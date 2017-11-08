//
// Created by Alice Santilli on 2017-11-08.
//

#ifndef MADAWASKA_WAVE_H
#define MADAWASKA_WAVE_H

#include <string>

using namespace std;


class Wave {

    // Wave elements
private :
    int cWave;
    int cHostileNum;
    int cHType;

public:
    Wave(int);
    int getWaveNumber();
    int getHostileAmount();
    int getHostileType();


};


#endif //MADAWASKA_WAVE_H
