
#include "stdafx.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>

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

void Projectile::travelFromTo(Hostile& hostile) {
	hostile.setDamageTaken(damage);
	if (hostile.getDamageTaken() >= hostile.getTotalHealth()) {
		hostile.isAlive = false;
		hostile.sprite.setColor(sf::Color::White);
	}
}

int Projectile::findTarget(HostileManager& manager, const float x, const float y)
{
	bool found = false;
	vector<Hostile> hostiles(manager.getHostile());
	float xpos, ypos;

	for (int m = 0; m < hostiles.size(); m++)
	{
		xpos = abs(hostiles.at(m).getPosition()[0] - x);
		ypos = abs(hostiles.at(m).getPosition()[1] - y);

		double dist = sqrt(xpos*xpos + ypos*ypos);

		if (dist <= range)
		{
			return m;
		}
	}

	return -1;
}
/*
Hostile Projectile::selectTarget()
{
	return hostilesAlive.get(findTarget());
}
*/

