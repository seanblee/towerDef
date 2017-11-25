#pragma once
#include <SFML/Graphics.hpp>
#include "HostileManager.h"
#include "Tower.h"
#include "Hostile.h"

using namespace std;
class Projectile {
private:
	sf::Sprite bullet;
	int range;
	int damage;

public:
	
	Projectile(int, int);
	void travelFromTo(Projectile, Hostile, HostileManager);
	int findTarget(HostileManager);
	//Hostile selectTarget();
};

