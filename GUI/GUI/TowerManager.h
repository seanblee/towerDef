#pragma once
#include <SFML/Graphics.hpp>
#include "Tower.h"

using namespace std;
class TowerManager {
private:
	vector<int> towerPrice;
	vector<Tower> towersBought;

public:

	TowerManager() {};

	//add function to initialize tower prices

	
	void addTower(Tower towerObj) {
		towersBought.push_back(towerObj);
	}
	void drawTowers(sf::RenderWindow &window) {
		for (Tower t : towersBought) {
			window.draw(t.getSprite());
		}
	}
	void clearAllTowers(){
		towersBought.clear();
	}

	int getPrice(int tower) {
		return towerPrice.at(tower - 1);
	}
};

