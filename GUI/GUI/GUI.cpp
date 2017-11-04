

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


cScreen::cScreen() {}

cScreen::cScreen(GUIStyle& tempStyle) {
	style = tempStyle;
}




void cScreen::moveSprite(sf::Sprite& sprite) {
	short int checkmove(-1);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		checkmove = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		checkmove = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		checkmove = 3;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		checkmove = 4;
	}

	switch (checkmove) {
	case -1 :
		break;
	case (1) :
		sprite.move(3,0);
		break;
	case(2):
		sprite.move(0,-3);
		break;
	case(3):
		sprite.move(-3,0);
		break;
	case(4):
		sprite.move(0,3);
		break;
	}
	return;
}

GUIStyle cScreen::getStyle() {
	return style;
}