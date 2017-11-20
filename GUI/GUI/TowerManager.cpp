#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "TowerManager.h"
#include "Tower.h"
#include <fstream>
#include "Cursor.h"

using namespace std;

TowerManager::TowerManager() {
	const char *infilename = "statSheet.txt";
	ifstream myfile(infilename);
	int temp;
	for(int i = 0; i < 3; i++){
		myfile >> temp;
		costs.push_back(temp);
	}
}
void TowerManager::addTower(int type, cursor cur) {
	Tower newTower(type, cur);
	towersBought.push_back(newTower);

}

void TowerManager::drawTowers(sf::RenderWindow &window) {
	for (Tower t : towersBought) {
		window.draw(t.getSprite());
	}
}

int TowerManager::getCost(int type) {
	return costs.at(type - 1);
}