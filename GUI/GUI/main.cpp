// WindowsProject2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.h"

int main(int argc, char** argv)
{

	sf::Font font;
	sf::Color bodycol(0, 0, 0);
	sf::Color bordercol(255, 255, 255);
	sf::Color textcol(255, 255, 255);

	sf::Texture spriteSheet;

	if (!spriteSheet.loadFromFile("SpriteSheet.png")) {/*put in exception later*/ }

	if (!font.loadFromFile("8bit16.ttf")) {/*put in exception later*/ }

	GUIStyle style(font, 2.0, bodycol, bordercol, textcol);

	//Applications variables
	std::vector<cScreen*> Screens;
	int screen = 0;

	//Window creation
	sf::RenderWindow window(sf::VideoMode(1000, 700), "Game Prototype");

	//Screens preparations
	MainMenu s0(style);
	Screens.push_back(&s0);
	WaveDescription s1(style);
	Screens.push_back(&s1);
	BuySellPage s2(style, spriteSheet);
	Screens.push_back(&s2);
	WaveRunningPage s3(style, spriteSheet);
	Screens.push_back(&s3);
	WaveComplete s4(style);
	Screens.push_back(&s4);
	LevelComplete s5(style);
	Screens.push_back(&s5);
	WinnerPage s6(style);
	Screens.push_back(&s6);
	GameOverPage s7(style);
	Screens.push_back(&s7);


	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(window);
	}

	return EXIT_SUCCESS;
}

