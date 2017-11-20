#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
class Projectile {
private:
	sf::Sprite bullet;
	int range;
	int damage;

public:
	
	Projectile(int, int);
	void travelFromTo(vector<int>, vector<int>);
};

