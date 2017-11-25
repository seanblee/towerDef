
#include "stdafx.h"

#include <SFML/Graphics.hpp>

using namespace std;

/*BuySell.cpp
	implements things in BuySell.h
*/

buySell::buySell() {
	
}

buySell::buySell(int n, sf::Texture& spriteSheet, GUIStyle& style) : numTowers(n) {
	
	//shape to push onto borders vector
	sf::RectangleShape tempBorder(sf::Vector2f(100, 100));
	style.setStyle(tempBorder);

	//number to push onto towerNums vector
	sf::Text tempNum;
	style.setStyle(tempNum, 16);

	//character value for tempNum, increments within for loop
	char j = '1';
	
	//initialize integers to set location of all things on the window
	int x = 500 - 50 - ((n/2) * 104);
	int y = 600;




	for (int i = 0; i < n; i++) {

		//loads tower sprite from sprite sheet
		sf::Sprite towersprite;
		towersprite.setTexture(spriteSheet);
		towersprite.setTextureRect(sf::IntRect(25*i, 0, 25, 25));
		towersprite.setPosition(x+25, y+25);
		towersprite.scale(2.0f, 2.0f);
		towersprite.setColor(sf::Color(i*100, 250-50*i,50*i+100)); //temp to distinguish different sprite images; 
		//will be removed once i actually make the sprite sheet

		//push onto towers vector
		towers.push_back(towersprite);

		//push a border onto the borders vector to correspond to this tower
		tempBorder.setPosition(x, y);
		borders.push_back(tempBorder);

		//pushing tower number onto towerNums vector
		tempNum.setString(j);
		tempNum.setPosition(x + 5, y + 5);
		towerNums.push_back(tempNum);

		j += 1;
		x += 104;
	}
	
	

}

//functions used when drawing window
//can directly pass in the number associated with tower, don't have to subtract one for the indexing

sf::Sprite buySell::getTower(int numTower) {
	return towers[numTower-1]; 
}
sf::RectangleShape buySell::getBorder(int numTower) {
	return borders[numTower-1];
}

sf::Text buySell::getText(int numTower) {
	return towerNums[numTower - 1];
}