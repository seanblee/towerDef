// doesthiswork.cpp : Defines the entry point for the application.
//

/*private:
	position location; //location on screen in pixels
	sf::Text message; //what pops up when loading it (theoretically)(like "loading: *message*")
						  //size of entity - width and height in pixels
	int w;
	int h;*/


#include "stdafx.h"

#include <SFML/Graphics.hpp>

using namespace std;

int main()
{

	sf::RenderWindow window(sf::VideoMode(1000, 700), "whhooOOOoOooOoO");

	sf::Font font;
	sf::Texture spriteSheet;
	sf::Color bodycol(0, 0, 0);
	sf::Color bordercol(255, 255, 255);
	sf::Color textcol(255, 255, 255);

	sf::RectangleShape testoverlays(sf::Vector2f(1000,700));
	testoverlays.setFillColor(sf::Color(0, 0, 0));

	if (!font.loadFromFile("8bit16.ttf")) {/*put in exception later*/}
	if (!spriteSheet.loadFromFile("SpriteSheet.png")) {/*put in exception later*/ }

	sf::Sprite testsprite;
	testsprite.setTexture(spriteSheet);
	testsprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	testsprite.setPosition(450, 450);
	

	GUIStyle style(font, 2, bodycol, bordercol, textcol);

	string easyPathMap("path1.jpg");
	path easyPath(easyPathMap, 10, 7);
	pathOverlays overlays;
	overlays.setStyle(style);
	buySell buySellOverlay(3, spriteSheet, style);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(easyPath.pathImage);

		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			window.clear();
			window.draw(testoverlays);
			window.draw(overlays.backing);
			window.draw(overlays.getHP());
			window.draw(overlays.getMoney());
			window.draw(overlays.getMessage());
			
			window.draw(buySellOverlay.getBorder(1));
			window.draw(buySellOverlay.getTower(1));
			window.draw(buySellOverlay.getBorder(2));
			window.draw(buySellOverlay.getTower(2));
			window.draw(buySellOverlay.getBorder(3));
			window.draw(buySellOverlay.getTower(3));

			window.draw(testsprite);
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
				easyPath.moveSprite(testsprite);
				
				window.clear();
				window.draw(testoverlays);
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
			window.display();
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {

			}
		}
	}

	return 0;
}
