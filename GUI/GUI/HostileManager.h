/*
* HostileManager.h
*
*  Created on: Nov 13, 2017
*      Author: donut
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "Hostile.h"

class HostileManager
{
private:
	vector <Hostile> hostilesAlive;

public:
	HostileManager() {};
	void spawn(Hostile host);
	bool isEveryoneDead();
	void killHost(Hostile host);
	int totalHostilesEliminated;
	int hostileKilledLastWave;

	vector<Hostile> getHostile() { return hostilesAlive; }

};
using namespace std;

void HostileManager::spawn(Hostile host)
{
	hostilesAlive.push_back(host);
}

bool HostileManager::isEveryoneDead()
{
	for (int col = 0; col < hostilesAlive.size(); col++) {
		if (hostilesAlive[col].isAlive == true) {
			return 0;
		}
	}
	return 1;
}

void HostileManager::killHost(Hostile host)
{
	int temp = host.idNum;
	hostilesAlive[host.idNum].isAlive = false;
	//hostilesAlive.erase(hostilesAlive.begin() + temp);
	//hostilesAlive.erase(remove(hostilesAlive.begin(), hostilesAlive.end(), host), hostilesAlive.end());
}
