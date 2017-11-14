//TEMPORARY until get wave.cpp
#pragma once
//
// Created by Alice Santilli on 2017-11-08.
//

#ifndef MADAWASKA_WAVE_H
#define MADAWASKA_WAVE_H

#include <string>
#include "stdafx.h"

using namespace std;


class Wave {

	// Wave elements
private:
	int cWave;
	int cHostileNum;
	int cHType;

public:
	Wave(int i) {
		cWave = i;
		cHostileNum = 20;
		cHType = 1;
	}
	int getWaveNumber() {
		return cWave;
	}
	int getHostileAmount() {
		return cHostileNum;
	}
	int getHostileType() {
		return cHType;
	}


};


#endif //MADAWASKA_WAVE_H