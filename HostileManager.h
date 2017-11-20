/*
 * HostileManager.h
 *
 *  Created on: Nov 13, 2017
 *      Author: donut
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "hostile.h"

class HostileManager
{
private:
	vector <Hostile> hostilesAlive;

public:
	HostileManager () {};
	void spawn (Hostile host);
	bool isEveryoneDead ();
	void killHost (Hostile host);
};
