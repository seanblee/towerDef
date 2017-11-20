#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
class Projectile {
private:
	sf::Sprite bullet;
	int range;
	int damage;

public:
	
	Projectile(int, int);
	void travelFromTo(sf::Vector2f, sf::Vector2f);
};

