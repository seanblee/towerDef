#include "HostileManager.h"
#include "stdafx.h"
#include "Hostile.h"

using namespace std;

void HostileManager::spawn(Hostile host)
{
	hostilesAlive.push_back(host);
}




bool HostileManager::isEveryoneDead()
{
	if (hostilesAlive.size() == 0)
	{
		return 1;
	}
	else
		return 0;
}

void HostileManager::killHost(Hostile host)
{
	int temp = host.idNum;
	hostilesAlive.erase(hostilesAlive.begin() + temp);
	//hostilesAlive.erase(remove(hostilesAlive.begin(), hostilesAlive.end(), host), hostilesAlive.end());
}
