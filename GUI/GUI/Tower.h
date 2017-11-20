#pragma once
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "Cursor.h"
#include <SFML/System/Vector2.hpp>


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
	void fireTo(sf::Vector2f);

	sf::Vector2f getPos() {
		return towerImage.getPosition;
	}

	int getCost() {
		return cost;
	}
	sf::Sprite getSprite() {
		return towerImage;
	}

	


};

