#pragma once
#include <SFML/Graphics.hpp>
#include "Tower.h"


using namespace std;
class TowerManager {
private:

	vector<Tower> towersBought;
	vector<int> costs;

public:

	TowerManager();
	void addTower(int, cursor);
	void drawTowers(sf::RenderWindow &);
	int getCost(int);
};

