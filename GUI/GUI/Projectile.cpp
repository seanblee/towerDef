
#include "stdafx.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include "Hostile.h"
#include "HostileManager.h"


using namespace std;

Projectile::Projectile(int dmg, int rad) {
	
	damage = dmg;
	range = rad;
}

void Projectile::travelFromTo(sf::Vector2f strt, sf::Vector2f nd, sf::RenderWindow &window)
{
	vector<int> start = { int(strt.x), int(strt.y) };
	bullet.move(strt);
	window.draw(bullet);
	vector<int> end = { int(nd.x), int(nd.y) };

	int dx = start[0] - end[0];
	int dy = start[1] - end[1];

	int MoveSpeed = 3;
	
	double incx = MoveSpeed / dx;
	double incy = MoveSpeed / dy;

	double x_th = start[0];
	double y_th = start[1];

	int x_r = start[0];
	int y_r = start[1];

	for (int n = 0; n < sqrt(dx*dx + dy*dy)/MoveSpeed; n++)
	{
		x_th = x_th + incx;
		y_th = y_th + incy;
		
		x_r = round(x_th);
		y_r = round(y_th);	
		sf::Vector2f newPos = sf::Vector2f(x_r, y_r);
		bullet.move(newPos);
		window.draw(bullet);

	}
}

int Projectile::findTarget(HostileManager manager)
{
	Hostile* currHost = new Hostile;
	int currPos = 0;
	bool found = false;

	for (int m = 0; m < manager.getHostile().size(); m++)
	{
		int xpos = manager.getHostile().at(m).getPosition()[0];
		int ypos = manager.getHostile().at(m).getPosition()[1];

		double dist = sqrt(xpos*xpos + ypos*ypos);

		if (dist <= range)
		{
			*currHost = manager.getHostile().at(m);
			currPos = m;
			found = true;
		}
	}

	if (found == true)
	{
		return currPos;
	}
	else
	{
		return -1;
	}
}
/*
Hostile Projectile::selectTarget()
{
	return hostilesAlive.get(findTarget());
}
*/

