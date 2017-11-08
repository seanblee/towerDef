#pragma once

#include "stdafx.h"
#include <SFML/Graphics.hpp>

using namespace std;

/*BuySell.h
	Header, stores the tower overlays that appear on the bottom of the screen of BuySellPage.h

	To do: get tower sprites from towerManager instead of doing them internally maybe
*/

class buySell {
private:

	int numTowers; //the total number of towers available to player
	vector<sf::Sprite> towers; //vector to store all the tower sprites; could eventually get from towerManager?
	vector<sf::RectangleShape> borders; //the borders for the tower sprites
	vector<sf::Text> towerNums; //sf::text objects labelling each tower

public:
	//constructors
	buySell();
	buySell(int, sf::Texture&, GUIStyle&);

	//accessors
	sf::Sprite getTower(int);
	sf::RectangleShape getBorder(int);
	sf::Text getText(int);


};
