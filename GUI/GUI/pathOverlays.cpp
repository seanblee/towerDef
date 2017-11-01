

#include "stdafx.h"

#include <SFML/Graphics.hpp>

using namespace std;

pathOverlays::pathOverlays() {

	string msg("path overlays");
	position loc(800, 0);
	initEntity(loc, 250, 150, msg);

	sf::RectangleShape rekt(sf::Vector2f(250, 150));
	rekt.setPosition(750, 0);
	
	backing = rekt;

	playerHP.setString("HP: 0");
	playerHP.setPosition(765, 20);


	playerMoney.setString("$: 0");
	playerMoney.setPosition(765, 50);

	statusMessage.setString("Status:\n\n Starting Game...");
	statusMessage.setPosition(765, 80);
	

}

pathOverlays::pathOverlays(string& HP, string& money, string& message) {
	
	HP = "HP: " + HP;
	playerHP.setString(HP);
	money = "$: " + money;
	playerMoney.setString(money);
	statusMessage.setString(message);
}

void pathOverlays::setStyle(GUIStyle& style) {
	backing.setFillColor(style.bodyCol);
	backing.setOutlineColor(style.borderCol);
	backing.setOutlineThickness(style.borderSize);

	playerHP.setFillColor(style.textCol);
	playerHP.setFont(style.font);
	playerHP.setCharacterSize(16);

	playerMoney.setFillColor(style.textCol);
	playerMoney.setFont(style.font);
	playerMoney.setCharacterSize(16);

	statusMessage.setFillColor(style.textCol);
	statusMessage.setFont(style.font);
	statusMessage.setCharacterSize(16);
}

void pathOverlays::updateHP(string& HP) {
	HP = "HP: " + HP;
	playerHP.setString(HP);
}

void pathOverlays::updateMoney(string& money) {
	money = "$: " + money;
	playerMoney.setString(money);
}

void pathOverlays::updateMessage(string& message) {
	statusMessage.setString(message);
}



sf::Text pathOverlays::getHP() {
	return (playerHP);
}
sf::Text pathOverlays::getMoney() {
	return (playerMoney);
}
sf::Text pathOverlays::getMessage() {
	return (statusMessage);
}