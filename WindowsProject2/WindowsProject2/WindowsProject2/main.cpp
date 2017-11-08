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
	//Applications variables
	std::vector<cScreen*> Screens;
	int screen = 0;

	//Window creation
	sf::RenderWindow window(sf::VideoMode(900, 600), "Game Prototype");

	//Screens preparations
	MainMenu s0;
	Screens.push_back(&s0);
	WaveDescription s1;
	Screens.push_back(&s1);
	BuySellPage s2;
	Screens.push_back(&s2);
	WaveRunningPage s3;
	Screens.push_back(&s3);
	WaveComplete s4;
	Screens.push_back(&s4);
	LevelComplete s5;
	Screens.push_back(&s5);
	WinnerPage s6;
	Screens.push_back(&s6);
	GameOverPage s7;
	Screens.push_back(&s7);


	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(window);
	}

	return EXIT_SUCCESS;
}

