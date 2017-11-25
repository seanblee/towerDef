#pragma once
#include <SFML/Graphics.hpp>

/*cursor.h
	header class that stores user-controlled cursor's current image and location
	only used in BuySellPage.h

	to do: put default cursor from BuySellPage.h in here maybe?

*/


class cursor {
private:
	
	sf::Vector2f location; //location of cursor in terms of game tiles
public:

	//current sprite displayed on cursor
	sf::Sprite cursorImage;

	//constructors
	cursor();
	cursor(sf::Sprite&);

	//functions to  change and move cursor
	void changeCursor(sf::Sprite&);
	void moveCursor();

	//get the locations of the cursor in terms of game tiles
	int getX();
	int getY();

	
};

