#pragma once
#include "stdafx.h"
#include "Tower.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Cursor.h"
#include "Projectile.h"

using namespace std;

Tower::Tower(int type, cursor cur) {
	towerType = type;
	switch (type) {
		case 1: 
			damage = 5;
			attackSpeed = 5;
			radius = 5;
		case 2:
			damage = 10;
			attackSpeed = 10;
			radius = 10;
		case 3:
			damage = 15;
			attackSpeed = 15;
			radius = 15;
	}
	towerImage = cur.getImage();
}

void Tower::fireTo(vector<int> location) {
	Projectile bullet;
}