#include "hostile.h";

Hostile (int id)
{
	if (id == 1)
	{
		// set stats for id1
		setidNum (1);
	}
	else if (id == 2)
	{
		// set stats for id2
		setidNum (2);
	}
	else if (id == 3)
	{
		// set stats for id3
		setidNum (3);
	}
	setPosition();
}

int Hostile::idNum ()
{
	return ID;
}

int Hostile::getTotalHealth ()
{
	return TotalHealth;
}

int Hostile::getMoveSpeed ()
{
	return MoveSpeed;
}

int Hostile::getDamageTaken ()
{
	return MoveSpeed;
}

std::vector<int> Hostile::getPosition ()
{
	return Position;
}

std::vector<int> Hostile::getNextPos ()
{
	std::vector<int>pos = getPosition();
	int locx = pos[0];
	int locy = pos[1];
	std::vector<int>nextPos [2] = new std::vector<int>;
	nextPos[0] = 0;
	nextPos[1] = 0;

	// FOR HOSTILES STARTING AT startPos == 1
	LOCATION1 = ; //the x-location of the first upwards turn
	LOCATION2 = ; //the y-location of the first turn to the horizontal
	LOCATION3 = ; //the x-location of the first downwards turn
	LOCATION4 = ; //the x-location of the second turn to the horizontal
	LOCATION5 = ; //the y-location of the upward turns

	// FOR HOSTILES STARTING AT startPos == 2
	LOCATION6 = ; //the x-location of the first upwards turn
	LOCATION7 = ; //the y-location of the first turn towards the horizontal
	LOCATION8 = ; //the x-location of the first downwards turn
	LOCATION9 = ; //the x-location of the xecond turn to the horizontal
	LOCATION10 = ; //the y-location of the upwards turn

	if (startPos == 1)
	{
		if (locx < LOCATION1 || (locx == LOCATION1 && locy == LOCATION2) || (locx < LOCATION3 && locx > LOCATION1) || (locx > LOCATION4))
		{
			nextPos[0] = locx+1;
			nextPos[1] = locy;
		}
		else if (locx == LOCATION1 && locy < LOCATION2) // if the x-position is on the first upwards part of the track
		{
			nextPos[0] = locx;
			nextPos[1] = locy+1;
		}
		else if (locx == LOCATION3 && locy > LOCATION5)
		{
			nextPos[0] = locx;
			nextPos[1] = locy-1;
		}
	}
	else
	{
		if (locx < LOCATION6 || (locx == LOCATION1 && locy == LOCATION7) || (locx < LOCATION8 && locx > LOCATION1) || (locx > LOCATION9))
		{
			nextPos[0] = locx+1;
			nextPos[1] = locy;
		}
		else if (locx == LOCATION1 && locy < LOCATION7) // if the x-position is on the first upwards part of the track
		{
			nextPos[0] = locx;
			nextPos[1] = locy+1;
		}
		else if (locx == LOCATION8 && locy > LOCATION10)
		{
			nextPos[0] = locx;
			nextPos[1] = locy-1;
		}
	}
	return nextPos;
}

void Hostile::setMoveSpeed (int ms)
{
	MoveSpeed = ms;
}

void Hostile::setDamageTaken (int dmg)
{
	DamageTaken = DamageTaken - dmg;
}

void Hostile::setidNum (int idNum)
{
	ID = idNum;
}

void Hostile::setPosition ()
{
	Position [0] = sprite.getPosition().x;
	Position [1] = sprite.getPosition().x;
}

void Hostile::takeDamage (int dmg)
{
	setDamageTaken (getTotalHealth () - getDamageTaken () - dmg);
}

bool Hostile::isDead ()
{
	if (checkHostileEndOfPath (host))
	{
		return true;
	}
	if (getDamageTaken (host) >= getTotalHealth (host))
	{
		return true;
	}
	return false;
}



