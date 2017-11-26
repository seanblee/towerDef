/*
* HostileManager.h
*
*  Created on: Nov 13, 2017
*      Author: donut
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "Hostile.h"


using namespace std;

class HostileManager
{


public:
	vector<Hostile> hostilesAlive;
	HostileManager() {};
	void spawn(Hostile host) {
		hostilesAlive.push_back(host);
	}
	bool isEveryoneDead() {
		for (int col = 0; col < hostilesAlive.size(); col++) {
			if (hostilesAlive[col].isAlive == true) {
				return 0;
			}
		}
		return 1;
	}
	void killHost(Hostile host) {
		int temp = host.idNum;
		hostilesAlive[host.idNum].isAlive = false;
		//hostilesAlive.erase(hostilesAlive.begin() + temp);
		//hostilesAlive.erase(remove(hostilesAlive.begin(), hostilesAlive.end(), host), hostilesAlive.end());
	}
	int totalHostilesEliminated;
	int hostileKilledLastWave;

	vector<Hostile> getHostile() { return hostilesAlive; }



};
