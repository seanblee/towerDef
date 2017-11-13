#pragma once
#include <SFML/Graphics.hpp>
#include "Tower.h"

using namespace std;
class TowerManager {
private:

	vector<Tower> towersBought;

public:

	void addTower(Tower towerObj) {
		towersBought.push_back(towerObj);
	}
	void drawTowers() {

	}

};

