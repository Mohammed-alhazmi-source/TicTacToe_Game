#pragma once
#include <iostream>
#include "clsWiner.h"
#include "TikTok.h"
#include <iomanip>
#include "clsScreen.h"
using namespace std;
class clsReturn
{
public:
	static string NameWin(clsWiner::enWiners Win)
	{
		if (Win == clsWiner::Computer)
			return "Computer";

		else if (Win == clsWiner::Player)
			return "PlayerX";

		else if (Win == clsWiner::NoWiner)
			return "NoWiner";
	}
};