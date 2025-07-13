#pragma once
#include <iostream>
#include <iomanip>
#include "TikTok.h"
#include "clsReturn.h"
#include "clsReadChoice.h"
#include "clsWiner.h"
#include "clsScreen.h"
#include "clsChangeColorScreen.h"
#include "clsUtil.h"
#include "clsGetWiner.h"
using namespace std;


class clsPlayYourSelfScreen : protected clsScreen
{	
	static void _PrintMessage()
	{
		cout << "\n\n" << setw(50) << left << "" << "Please Enter Choice From 1 To 9 ?\n";
	}

	static void _CleanScreenAndPrintTableGame(char _Matrix[3][3])
	{
		system("cls");
		system("Color 0F");
		_DrawTableGameTipTop(_Matrix, "PlayerX Vs PlayerO");
	}

public:
	static void StartGame()
	{
		char _MatrixTikTok[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
		short ChoicesPlayerX = 0, ChoicesPlayerO = 0;
		char Player;
		char Answer = 'n';

		do
		{
			_CleanScreenAndPrintTableGame(_MatrixTikTok);
			for (int i = 0; i < 9; i++)
			{
				_PrintMessage();
				Player = clsReadChoice::_ReadChoicePlayerX(_MatrixTikTok, ChoicesPlayerX);
				_RefreshTableGameTipTop(Player, TikTok::enPlayers::PlayerX, _MatrixTikTok);

				if (clsGetWiner::GetWinerGame(ChoicesPlayerX, ChoicesPlayerO, _MatrixTikTok))
					break;

				_CleanScreenAndPrintTableGame(_MatrixTikTok);
				_PrintMessage();

				Player = clsReadChoice::_ReadChoicePlayerO(_MatrixTikTok, ChoicesPlayerO);
				_RefreshTableGameTipTop(Player, TikTok::enPlayers::PlayerO, _MatrixTikTok);

				if (clsGetWiner::GetWinerGame(ChoicesPlayerX, ChoicesPlayerO, _MatrixTikTok))
					break;

				_CleanScreenAndPrintTableGame(_MatrixTikTok);
			}

			cout << endl << setw(52) << left << "";
			Answer = clsUtil::DoYouWantToContinue("Do You Want To Play More ? y/n ? ");

			if (Answer == 'Y' || Answer == 'y')
			{
				_RebuildTableGameTipTop(_MatrixTikTok);
				ChoicesPlayerX = ChoicesPlayerO = 0;
			}

		} while (Answer == 'Y' || Answer == 'y');			
	}
};