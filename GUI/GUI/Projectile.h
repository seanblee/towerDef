#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "HostileManager.h"

using namespace std;
class Projectile {
private:
	sf::Sprite bullet;
	int range;
	int damage;

public:
	

	Projectile();
	Projectile(int, int);
	void travelFromTo(Hostile&);
	int findTarget(HostileManager&, const float, const float);
	//Hostile selectTarget();
};

