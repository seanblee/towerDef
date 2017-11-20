#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "TowerManager.h"
#include "Tower.h"
#include <fstream>
#include "Cursor.h"

using namespace std;

void TowerManager::addTower(int type, cursor cur) {
	Tower newTower(type, cur);
	towersBought.push_back(newTower);

	const char *infilename = "statSheet.txt";
	ifstream myfile(infilename);

	string temp;
	while (!myfile.eof()) {
		getline(myfile, temp, ',');
		int i = stoi(temp);
		if (i != NULL) {
			costs.push_back(i);
		}
	}

}

void TowerManager::drawTowers(sf::RenderWindow &window) {
	for (Tower t : towersBought) {
		window.draw(t.getSprite());
	}
}

int TowerManager::getCost(int type) {
	return costs.at(type - 1);
}