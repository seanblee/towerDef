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

};
using namespace std;

void HostileManager::spawn(Hostile host)
{
	hostilesAlive.push_back(host);
}

bool HostileManager::isEveryoneDead()
{
	if (hostilesAlive.size() == 0)
	{
		return 1;
	}
	else
		return 0;
}

void HostileManager::killHost(Hostile host)
{
	int temp = host.idNum;
	hostilesAlive.erase(hostilesAlive.begin() + temp);
	//hostilesAlive.erase(remove(hostilesAlive.begin(), hostilesAlive.end(), host), hostilesAlive.end());
}
