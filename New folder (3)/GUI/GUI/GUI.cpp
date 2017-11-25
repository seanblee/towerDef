

#include "stdafx.h"

#include <SFML/Graphics.hpp>

using namespace std;

/*GUI.cpp

**took out all the position functions bc unused


*/

//constructors
GUIStyle::GUIStyle() {}

GUIStyle::GUIStyle(sf::Font font, float borderSize,
	sf::Color bodyColour, sf::Color borderColour, sf::Color textColour) :
		bodyCol(bodyColour), 
		borderCol(borderColour),
		textCol(textColour),
		font(font), 
		borderSize(borderSize) {}

//setStyle functions

void GUIStyle::setStyle(sf::Text& text, int fontSize) {
	text.setFillColor(textCol);
	text.setFont(font);
	text.setCharacterSize(fontSize);
}
void GUIStyle::setStyle(sf::RectangleShape& rect) {
	rect.setFillColor(bodyCol);
	rect.setOutlineColor(borderCol);
	rect.setOutlineThickness(borderSize);
}




//******cScreen implementation code
//i don't remember why this is here but it is i'll move it later

cScreen::cScreen() {}

cScreen::cScreen(GUIStyle& tempStyle) {
	style = tempStyle;
}


GUIStyle cScreen::getStyle() {
	return style;
}