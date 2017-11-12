#pragma once

#include "stdafx.h"
#include <SFML/Graphics.hpp>

/*screenManager.h

Manages screens, keeps track of current screen and next screen, next screen can be altered by gameLogic probably

*/

class screenManager {
public:
	std::vector<cScreen*> Screens;
	int currentScreen;
	int nextScreen;

	screenManager();

	void runScreens(sf::RenderWindow& window); //code that runs all the screens
	//screens return the value of the next screen, and that value is then put into the currentscreen variable
	
	int getScreenNum(cScreen&); //gives you screen number of a screen object
	void setNextScreen(int); //sets value of the next screen
};

inline void screenManager::runScreens(sf::RenderWindow& window) {
	nextScreen = Screens[currentScreen]->Run(window);
	//could put gamelogic functions here, otherwise default is what screen returns
	currentScreen = nextScreen;
}