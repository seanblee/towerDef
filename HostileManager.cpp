#include "HostileManager.h"
#include <algorithm>
#include <iostream>
using namespace std;

void HostileManager::spawn (Hostile host)
{
	spawnHostile (host);
	hostilesAlive.push_back(host);
}

bool HostileManager::isEveryoneDead ()
{
	if (hostilesAlive.length() == 0)
	{
		return 1;
	}
	else
		return 0;
}

void HostileManager::killHost (Hostile host)
{
	hostilesAlive.erase(remove(hostilesAlive.begin(), hostilesAlive.end(), host), hostilesAlive.end());
}
