#pragma once
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "Cursor.h"

class Tower {
private:

	sf::Sprite towerImage;
	vector<int> position;
	int towerType;
	int damage;
	int attackSpeed;
	int cost;
	int radius;

public:

	Tower(int type, cursor cur);
	void fireTo(vector<int>);

	vector<int> getPos() {
		return towerImage.getPosition;
	}

	int getCost() {
		return cost;
	}
	sf::Sprite getSprite() {
		return towerImage;
	}

	


};

