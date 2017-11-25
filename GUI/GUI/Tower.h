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
		return towerImage.getPosition().x;
	}
	int getY() {
		return towerImage.getPosition().y;
	}

	sf::Sprite getSprite() {
		return towerImage;
	}
	void fireTower(HostileManager manager, sf::RenderWindow &window) {
		Projectile bullet = Projectile(5,5);
		int index = bullet.findTarget(manager);
		bullet.travelFromTo(bullet, index, manager);

	}


};