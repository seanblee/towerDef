

#include "stdafx.h"

#include <SFML/Graphics.hpp>

using namespace std;

position::position() : x(0), y(0) {}

position::position(int a, int b) : x(a), y(b) {}


void position::setLocation(int a, int b){
	x = a;
	y = b;
	
}

int position::getX() { return x; }
int position::getY() { return y; }

GUIStyle::GUIStyle() {}

GUIStyle::GUIStyle(sf::Font font, float borderSize,
	sf::Color bodyColour, sf::Color borderColour, sf::Color textColour) :
		bodyCol(bodyColour), 
		borderCol(borderColour),
		textCol(textColour),
		font(font), 
		borderSize(borderSize) {}

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






cScreen::cScreen() {}

cScreen::cScreen(GUIStyle& tempStyle) {
	style = tempStyle;
}


GUIStyle cScreen::getStyle() {
	return style;
}