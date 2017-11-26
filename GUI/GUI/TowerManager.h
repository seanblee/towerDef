#pragma once
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "Tower.h"

using namespace std;
class TowerManager {
private:

	vector<Tower> towersBought;

public:

	TowerManager() {};
	vector<Tower> getTowerVector() {
		return towersBought;
	}
	void addTower(Tower towerObj) {
		towersBought.push_back(towerObj);
	}
	void drawTowers(sf::RenderWindow &window) {
		for (Tower t : towersBought) {
			window.draw(t.getSprite());
		}
	}
	void fireTowers(HostileManager& manager) {
		for (Tower t : towersBought) {
			t.fireTower(manager);
		}
	}
	void clearAllTowers(){
		towersBought.clear();
	}
};

