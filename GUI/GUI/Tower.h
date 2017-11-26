#pragma once
#include "stdafx.h"
#include "Projectile.h"
#include <fstream>

class Tower {
private:

	sf::Sprite towerImage;
	Projectile bullet;
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
		bullet = Projectile(1000, 1000);

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
	void fireTower(HostileManager& manager) {

		int index = bullet.findTarget(manager, towerImage.getPosition().x, towerImage.getPosition().y);
		bullet.travelFromTo(manager.hostilesAlive[index]);

	}


};