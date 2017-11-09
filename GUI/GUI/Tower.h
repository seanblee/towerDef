#pragma once
#include <SFML/Graphics.hpp>
class Tower {
private:

	sf::Sprite towerImage;
	int x;
	int y;
	int type;
	int damage;
	int attackSpeed;
	int cost;
	int radius;

public:

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}


};

