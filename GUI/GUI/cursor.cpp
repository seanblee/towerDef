#include <SFML/Graphics.hpp>
#include "stdafx.h"

/*Cursor.cpp
	implements cursor class
*/

//constructors
cursor::cursor() {
}

cursor::cursor(sf::Sprite& defaultCursor) {

	location.x = 0;
	location.y = 0;
	cursorImage = defaultCursor;
	cursorImage.setPosition(sf::Vector2f(10, 10));
	cursorImage.setScale(1.2f, 1.2f);

}

//change cursor image
void cursor::changeCursor(sf::Sprite& newImage) {
	sf::Vector2f position(cursorImage.getPosition());
	cursorImage = newImage;
	cursorImage.setPosition(position);
	cursorImage.setScale(1.2f, 1.2f);
}


//move cursor
//has logic for listening to keyboard input

void cursor::moveCursor() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && location.x <=20) {
		cursorImage.move(50, 0);
		location.x += 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && location.y >=1) {
		cursorImage.move(0, -50);
		location.y -= 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && location.x >=1 ) {
		cursorImage.move(-50, 0);
		location.x -= 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && location.y <=20) {
		cursorImage.move(0, 50);
		location.y += 1;
	}
		return;
}

int cursor::getX() {
	return location.x;
}

int cursor::getY() {
	return location.y;
}