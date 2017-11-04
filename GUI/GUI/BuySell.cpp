
#include "stdafx.h"

#include <SFML/Graphics.hpp>

using namespace std;

buySell::buySell() {
	
}

buySell::buySell(int n, sf::Texture& spriteSheet, GUIStyle& style) : numTowers(n) {
	

	sf::RectangleShape tempBorder(sf::Vector2f(100, 100));
	tempBorder.setFillColor(style.bodyCol);
	tempBorder.setOutlineColor(style.borderCol);
	tempBorder.setOutlineThickness(style.borderSize);

	sf::Text tempNum;
	tempNum.setCharacterSize(16);
	tempNum.setFillColor(style.textCol);
	tempNum.setFont(style.font);
	

	int x = 500 - 50 - ((n/2) * 104);
	int y = 600;
	char j = '1';


	for (int i = 0; i < n; i++) {
		sf::Sprite towersprite;
		towersprite.setTexture(spriteSheet);
		towersprite.setTextureRect(sf::IntRect(25*i, 0, 25, 25));
		towersprite.setPosition(x+25, y+25);
		towersprite.scale(2.0f, 2.0f);
		towers.push_back(towersprite);

		tempBorder.setPosition(x, y);
		borders.push_back(tempBorder);

		tempNum.setString(j);
		j += 1;
		tempNum.setPosition(x + 5, y + 5);
		towerNums.push_back(tempNum);

		x += 104;
	}
	
	

}


sf::Sprite buySell::getTower(int numTower) {
	return towers[numTower-1];
}
sf::RectangleShape buySell::getBorder(int numTower) {
	return borders[numTower-1];
}

sf::Text buySell::getText(int numTower) {
	return towerNums[numTower - 1];
}