#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Projectile.h"

using namespace std;

Projectile::Projectile(int dmg, int rad) {
	
	damage = dmg;
	range = rad;
}

void Projectile::travelFromTo(vector<int> start, vector<int> end) {
	bullet.
}