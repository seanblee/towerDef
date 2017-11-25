#pragma once
#include "stdafx.h"
#include "Projectile.h"
#include "HostileManager.h"

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
	void fireTower(HostileManager manager, sf::RenderWindow &window) {
		Projectile bullet = Projectile(5,5);
		int index = bullet.findTarget(manager);
		sf::Vector2f towerLoc(getX(), getY());
		sf::Vector2f hostileLoc(manager.getHostile().at(index).getPosition()[0], manager.getHostile().at(index).getPosition()[1]);
		bullet.travelFromTo(towerLoc, hostileLoc, window);

	}


};