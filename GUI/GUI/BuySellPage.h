#pragma once
#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
class BuySellPage : public cScreen
{
	sf::Texture spriteSheet;
public:
	BuySellPage(GUIStyle& style, sf::Texture sheet) : cScreen(style) { spriteSheet = sheet; }
	virtual int Run(sf::RenderWindow &window);
};

int BuySellPage::Run(sf::RenderWindow &window)
{
	//I found this came in handy for positioning
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;


	GUIStyle style(getStyle());

	sf::Sprite testsprite;
	testsprite.setTexture(spriteSheet);
	testsprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	testsprite.setPosition(450, 450);
	testsprite.setColor(style.bodyCol); //delete later

	string easyPathMap("path1.jpg");
	string userMessage = "Buy some towers";
	path easyPath(easyPathMap, 10, 7);
	pathOverlays overlays;
	overlays.setStyle(style);
	overlays.updateMessage(userMessage);
	buySell buySellOverlay(3, spriteSheet, style);

	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//if they click the x in top corner close window
			if (event.type == sf::Event::Closed) {
				window.close();
				return -1;
			}

			if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Return)
				{
					//click enter to go to waverunning page
					return 3;
				}
			}

			moveSprite(testsprite);
			
			window.clear();
			window.draw(easyPath.pathImage);
			window.draw(overlays.backing);
			window.draw(overlays.getHP());
			window.draw(overlays.getMoney());
			window.draw(overlays.getMessage());

			window.draw(buySellOverlay.getBorder(1));
			window.draw(buySellOverlay.getTower(1));
			window.draw(buySellOverlay.getText(1));
			window.draw(buySellOverlay.getBorder(2));
			window.draw(buySellOverlay.getTower(2));
			window.draw(buySellOverlay.getText(2));
			window.draw(buySellOverlay.getBorder(3));
			window.draw(buySellOverlay.getTower(3));
			window.draw(buySellOverlay.getText(3));

			window.draw(testsprite);
			window.display();
		}

	}
}