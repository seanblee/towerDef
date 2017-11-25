#pragma once
#include <SFML/Graphics.hpp>
#include "HostileManager.h"

using namespace std;
class Projectile {
private:
	sf::Sprite bullet;
	int range;
	int damage;

public:
	
	Projectile(int, int);
	void travelFromTo(sf::Vector2f, sf::Vector2f, sf::RenderWindow &window);
	int findTarget(HostileManager manager);
	//Hostile selectTarget();
};

