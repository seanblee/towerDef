/*
 * hostile.h
 *
 *  Created on: Oct 4, 2017
 *      Author: donut
 */
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "WaveRunningPage.h"

class Hostile
{
public:
	sf::Sprite sprite;
	Hostile (int id);
	int idNum ();
	int getTotalHealth ();
	int getMoveSpeed ();
	int getDamageTaken ();
	std::vector<int> getPosition ();
	std::vector<int> getNextPos ();
	void setMoveSpeed (int ms);
	void setDamageTaken (int dmg);
	void setidNum (int idNum);
	void setPosition ();
	void takeDamage (int dmg)
	bool isDead ();

private:
	const int TotalHealth;
	int MoveSpeed;
	int DamageTaken;
	const int ID;
	std::vector <int> Position; // current position
	int startPos; // 1 = lower track, 2 = upper track
};

