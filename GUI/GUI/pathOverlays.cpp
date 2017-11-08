

#include "stdafx.h"
#include <string>

#include <SFML/Graphics.hpp>

using namespace std;

pathOverlays::pathOverlays() {

	

	sf::RectangleShape rekt(sf::Vector2f(250, 175));
	rekt.setPosition(750, 0);
	
	backing = rekt;

	playerHP.setString("HP: 0");
	playerHP.setPosition(770, 20);


	playerMoney.setString("$: 0");
	playerMoney.setPosition(770, 50);

	statusMessage.setString("Starting Game...");
	statusMessage.setPosition(770, 85);

	optionsMessage.setString(" ");
	optionsMessage.setPosition(770, 115);
	

}

pathOverlays::pathOverlays(string& HP, string& money, string& message) {
	
	HP = "HP: " + HP;
	playerHP.setString(HP);
	money = "$: " + money;
	playerMoney.setString(money);
	statusMessage.setString(message);
}

void pathOverlays::setStyle(GUIStyle& style) {
	style.setStyle(backing);

	style.setStyle(playerHP, 19);
	style.setStyle(playerMoney, 19);

	style.setStyle(statusMessage, 19);
	style.setStyle(optionsMessage, 16);
}

void pathOverlays::setHP(int HP) {
	string HPStr = to_string(HP);
	HPStr = "HP: " + HPStr;
	playerHP.setString(HPStr);
}

void pathOverlays::setMoney(int money) {
	string moneyStr = to_string(money);
	moneyStr = "$: " + moneyStr;
	playerMoney.setString(moneyStr);
}

void pathOverlays::setMessage(string& message) {
	statusMessage.setString(message);
}

void pathOverlays::setOptions(string& message) {
	optionsMessage.setString(message);
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
sf::Text pathOverlays::getOptions() {
	return (optionsMessage);
}