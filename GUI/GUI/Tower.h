#pragma once
#include "stdafx.h"
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

	Tower(sf::Sprite img) {
		towerImage = img;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}

	sf::Sprite getSprite() {
		return towerImage;
	}


};