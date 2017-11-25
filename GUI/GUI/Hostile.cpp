
#include "stdafx.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include "Hostile.h"


using namespace std;

Hostile::Hostile() {}

std::vector<int> Hostile::getNextPos()
{
	std::vector<int>pos = getPosition();
	int locx = pos[0];
	int locy = pos[1];
	std::vector <int> nextPos;
	nextPos.push_back(0);
	nextPos.push_back(1);

	// FOR HOSTILES STARTING AT startPos == 1
	int LOCATION1 = 307; //the x-location of the first upwards turn
	int LOCATION2 = 206; //the y-location of the first turn to the horizontal
	int LOCATION3 = 657; //the x-location of the first downwards turn
	int LOCATION4 = 657;//the x-location of the second turn to the horizontal
	int LOCATION5 = 504; //the y-location of the upward turns

						 // FOR HOSTILES STARTING AT startPos == 2
	int LOCATION6 = 256; //the x-location of the first upwards turn
	int LOCATION7 = 157; //the y-location of the first turn towards the horizontal
	int LOCATION8 = 706; //the x-location of the first downwards turn
	int LOCATION9 = 706; //the x-location of the xecond turn to the horizontal
	int LOCATION10 = 457; //the y-location of the upwards turn

	if (startPos == 1)
	{
		if (locx < LOCATION1 || (locx == LOCATION1 && locy == LOCATION2) || (locx < LOCATION3 && locx > LOCATION1) || (locx > LOCATION4) || (locy == LOCATION5&&locx >= LOCATION4))
		{
			nextPos[0] = locx + 1;
			nextPos[1] = locy;
		}
		else if (locx == LOCATION1 && locy > LOCATION2) // if the x-position is on the first upwards part of the track
		{
			nextPos[0] = locx;
			nextPos[1] = locy - 1;
		}
		else if (locx == LOCATION3 && locy < LOCATION5)
		{
			nextPos[0] = locx;
			nextPos[1] = locy + 1;
		}
	}
	else
	{
		if (locx < LOCATION6 || (locx == LOCATION6 && locy == LOCATION7) || (locx < LOCATION8 && locx > LOCATION6) || (locx > LOCATION9) || (locy == LOCATION10&&locx >= LOCATION9))
		{
			nextPos[0] = locx + 1;
			nextPos[1] = locy;
		}
		else if (locx == LOCATION6 && locy > LOCATION7) // if the x-position is on the first upwards part of the track
		{
			nextPos[0] = locx;
			nextPos[1] = locy - 1;
		}
		else if (locx == LOCATION8 && locy < LOCATION10)
		{
			nextPos[0] = locx;
			nextPos[1] = locy + 1;
		}
	}

	return nextPos;
}
Hostile::Hostile(int id)
{
	if (id == 1)
	{
		// set stats for id1
		TotalHealth = 100;
		MoveSpeed = 1;
		DamageTaken = 0;
		type = 1;

	}
	else if (id == 2)
	{
		// set stats for id2
		TotalHealth = 200;
		MoveSpeed = 5;
		DamageTaken = 0;
		type = 2;

	}
	else if (id == 3)
	{
		TotalHealth = 500;
		MoveSpeed = 10;
		DamageTaken = 0;
		type = 3;

	}

	setPosition();

}



int Hostile::getTotalHealth()
{
	return TotalHealth;
}

int Hostile::getMoveSpeed()
{
	return MoveSpeed;
}

int Hostile::getDamageTaken()
{
	return MoveSpeed;
}

std::vector<int> Hostile::getPosition()
{
	return Position;
}


void Hostile::setMoveSpeed(int ms)
{
	MoveSpeed = ms;
}

void Hostile::setDamageTaken(int dmg)
{
	DamageTaken = DamageTaken - dmg;
}

void Hostile::setidNum(int idNum)
{
	ID = idNum;
}

void Hostile::setPosition()
{
	if (getPosition().size() == 0) {
		Position.push_back(sprite.getPosition().x);
		Position.push_back(sprite.getPosition().y);
	}
	else {

		Position[0] = sprite.getPosition().x;
		Position[1] = sprite.getPosition().y;
	}

}

void Hostile::takeDamage(int dmg)
{
	setDamageTaken(getTotalHealth() - getDamageTaken() - dmg);
}

bool Hostile::isDead()
{
	if (getDamageTaken() >= getTotalHealth())
	{
		return true;
	}
	return false;
}



