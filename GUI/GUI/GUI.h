#pragma once

#include "stdafx.h"

#include <SFML/Graphics.hpp>

/*GUI.h
	*removed position class, unused*

	contains GUIStyle class, which has all the style attributes 
	needed for sf::text and sf::rectangleshape GUI elements

*/


using namespace std;

class GUIStyle {
public:
	//all the colours
	sf::Color bodyCol;
	sf::Color borderCol;
	sf::Color textCol;
	sf::Font font;

	//border thickness
	float borderSize;

	//constructors
	GUIStyle();
	GUIStyle(sf::Font font, float borderSize,
		sf::Color bodyCol, sf::Color borderCol, sf::Color textCol);

	//set the style of a given sf::Text or sf::RectangleShape object
	void setStyle(sf::Text&, int); //also pass in characterSize
	void setStyle(sf::RectangleShape&);

};






