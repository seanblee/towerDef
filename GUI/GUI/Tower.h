#pragma once
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "BuySell.h"
class Tower {
private:

	sf::Sprite towerImage;
	int x;
	int y;
	int towerType;
	int damage;
	int attackSpeed;
	int cost;
	int radius;

public:

	Tower(int type, buySell overlay);

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getCost() {
		return cost;
	}
	sf::Sprite getSprite() {
		return towerImage;
	}


};

