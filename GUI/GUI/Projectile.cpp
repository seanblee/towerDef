
#include "stdafx.h"/*
#include "Projectile.h"
#include <SFML/Graphics.hpp>


using namespace std;

Projectile::Projectile(int dmg, int rad) {
	
	damage = dmg;
	range = rad;
}

void Projectile::travelFromTo(vector<int> start, vector<int> end) 
{
	int dx = start[0] - end[0];
	int dy = start[1] - end[1];
	
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
	}
}

int Projectile::findTarget()
{
	Hostile* currHost = new Hostile;
	int currPos = 0;
	bool found = false;

	for (int m = 0; m < hostilesAlive.length(); m++)
	{
		int xpos = hostilesAlive.at(m).getPosition()[0];
		int ypos = hostilesAlive.at(m).getPosition()[1];

		double dist = sqrt(xpos*xpos + ypos*ypos);

		if (dist <= range)
		{
			currHost = hostilesAlive.at(m);
			curPoss = m;
			found = true;
		}
	}

	if (found == true)
	{
		return m;
	}
	else
	{
		return -1;
	}
}

Hostile Projecile::selectTarget()
{
	return hostilesAlive.get(findTarget());
}

*/