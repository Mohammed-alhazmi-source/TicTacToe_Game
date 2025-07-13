#pragma once
#include <iostream>
#include <iomanip>
#include "clsReturn.h"
#include "clsWiner.h"
#include "clsScreen.h"
#include "clsChangeColorScreen.h"

class clsGetWiner
{
public:
	static bool GetWinerGame(short ChoicesPlayerX, short ChoicesPlayerO, char _MatrixTikTok[3][3])
	{
		if (ChoicesPlayerX >= 3 || ChoicesPlayerO >= 3)
		{
			clsWiner::enWiners win = clsWiner::_HasBeenWinGame(_MatrixTikTok, ChoicesPlayerX, ChoicesPlayerO);
			if (win != clsWiner::enWiners::Continue)
			{
				clsChangeColorScreen::ChangeColorScreen(win);
				string NameWiner = clsReturn::NameWin(win);

				if (NameWiner == "NoWiner")
					clsScreen::_DrawTableGameTipTop(_MatrixTikTok, (NameWiner + " : Equal"));

				else
					clsScreen::_DrawTableGameTipTop(_MatrixTikTok, (NameWiner == "Computer" ? " Winer : PlayerO" : " Winer : " + NameWiner));
				
				return true;
			}
		}
		return false;
	}
};