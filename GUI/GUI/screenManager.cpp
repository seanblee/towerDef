
#include "stdafx.h"
#include <SFML/Graphics.hpp>

screenManager::screenManager() {
	currentScreen = 0;
	nextScreen = 1;
}



int screenManager::getScreenNum(cScreen& screen) {
	if (typeid(screen).name() == typeid(MainMenu).name()) {
		return 0;
	}
	if (typeid(screen).name() == typeid(WaveDescription).name()) {
		return 1;
	}
	if (typeid(screen).name() == typeid(BuySellPage).name()) {
		return 2;
	}
	if (typeid(screen).name() == typeid(WaveRunningPage).name()) {
		return 3;
	}
	if (typeid(screen).name() == typeid(WaveComplete).name()) {
		return 4;
	}
	if (typeid(screen).name() == typeid(LevelComplete).name()) {
		return 5;
	}
	if (typeid(screen).name() == typeid(WinnerPage).name()) {
		return 6;
	}
	if (typeid(screen).name() == typeid(GameOverPage).name()) {
		return 7;
	}
}

void screenManager::setNextScreen(int screenNum) {
	nextScreen = screenNum;
}