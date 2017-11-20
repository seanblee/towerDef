#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include <SFML/System/Vector2.hpp>

using namespace std;

Projectile::Projectile(int dmg, int rad) {
	sf::Sprite bullet;
	sf::Texture spriteSheet;
	if (!spriteSheet.loadFromFile("SpriteSheet.png"))
	bullet.setTexture(spriteSheet);
	bullet.setTextureRect(sf::IntRect(0, 0, 5, 5));
	sf::Color col(255, 255, 255);
	bullet.setColor(col);
	damage = dmg;
	range = rad;
}

void Projectile::travelFromTo(sf::Vector2f, sf::Vector2f) {
	bullet.
}