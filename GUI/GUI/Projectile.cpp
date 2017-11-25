
#include "stdafx.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include "Hostile.h"
#include "HostileManager.h"
#include "Tower.h"


using namespace std;

Projectile::Projectile() {}

Projectile::Projectile(int dmg, int rad) {
	sf::Texture spriteSheet; 
	spriteSheet.loadFromFile("SpriteSheet.png");
	sf::Sprite bullet;
	bullet.setTexture(spriteSheet);
	bullet.setTextureRect(sf::IntRect(0, 0, 5, 5));
	bullet.setColor(sf::Color::Black);
	damage = dmg;
	range = rad;
}

void Projectile::travelFromTo(Projectile bullet, Hostile hostile, HostileManager manager) {
	hostile.setDamageTaken(bullet.damage);
	if (hostile.isDead()) hostile.isAlive == false;
}

int Projectile::findTarget(HostileManager manager)
{
	int currPos = 0;
	bool found = false;

	for (int m = 0; m < manager.getHostile().size(); m++)
	{
		int xpos = manager.getHostile().at(m).getPosition()[0];
		int ypos = manager.getHostile().at(m).getPosition()[1];

		double dist = sqrt(xpos*xpos + ypos*ypos);

		if (dist <= range)
		{
			currPos = m;
			found = true;
		}
	}

	if (found == true)
	{
		return currPos;
	}
	else
	{
		return -1;
	}
}
/*
Hostile Projectile::selectTarget()
{
	return hostilesAlive.get(findTarget());
}
*/

