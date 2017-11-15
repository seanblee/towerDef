#pragma once
#include <SFML/Graphics.hpp>

class cursor {
private:
	
	sf::Vector2f location; //location of cursor in tile
public:


	sf::Sprite cursorImage;

	cursor();
	cursor(sf::Sprite&);

	void changeCursor(sf::Sprite&);
	void moveCursor();

	int getX();
	int getY();

	sf::Sprite getImage() { return cursorImage; };

	
};

