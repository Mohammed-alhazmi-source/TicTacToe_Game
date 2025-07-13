#pragma once
#include "clsWiner.h"
class clsChangeColorScreen
{
public:
	static void ChangeColorScreen(clsWiner::enWiners Win)
	{
		system("cls");

		if (Win == clsWiner::enWiners::Player)
			system("Color 2F");

		else if (Win == clsWiner::enWiners::Computer)
			system("Color 4F");

		else if (Win == clsWiner::enWiners::NoWiner)
			system("Color 6F");
	}
};