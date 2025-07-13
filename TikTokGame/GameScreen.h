#pragma once
#include <iostream>
#include <iomanip>
#include "TikTok.h"
#include "clsPrint.h"
#include "clsReadChoice.h"
#include "clsWiner.h"
#include "clsScreen.h"
#include "clsChangeColorScreen.h"
#include <sstream>
#include "clsUtil.h"
using namespace std;

class GameScreen : protected clsScreen
{
private:
	static bool _GetWinerGame(short ChoicesX, short ChoicesO, char _MatrixTikTok[3][3])
	{
		if (ChoicesX >= 3 || ChoicesO >= 3)
		{
			clsWiner::enWiners win = clsWiner::_HasBeenWinGame(_MatrixTikTok, ChoicesX, ChoicesO);
			if (win != clsWiner::enWiners::Continue)
			{
				clsChangeColorScreen::ChangeColorScreen(win);
				_DrawTableGameTipTop(_MatrixTikTok);
				ostringstream NameWiner(clsReturn::NameWin(win));
				cout << endl << endl << setw(54) << left << "" << "Winer The Game Is " << NameWiner.str();
				cout << endl;
				return true;
			}
		}
		return false;
	}
public:
	static void StartGame()
	{
		char _MatrixTikTok[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
		short ChoicesX = 0, ChoicesO = 0;
		char Player;
		char Answer = 'n';

		do
		{
			system("cls");
			system("Color 0F");
			for (int i = 0; i < 9; i++)
			{
				_DrawTableGameTipTop(_MatrixTikTok);
				cout << "\n\n" << setw(50) << left << "" << "Please Enter Choice From 1 To 9 ?\n";

				Player = clsReadChoice::_ReadChoicePlayerX(_MatrixTikTok, ChoicesX);
				_RefreshTableGameTipTop(Player, TikTok::enPlayers::PlayerX, _MatrixTikTok);

				if (_GetWinerGame(ChoicesX, ChoicesO, _MatrixTikTok))
					break;

				Player = clsReadChoice::_ReadChoiceComputer(_MatrixTikTok, ChoicesO);
				_RefreshTableGameTipTop(Player, TikTok::enPlayers::PlayerO, _MatrixTikTok);

				if (_GetWinerGame(ChoicesX, ChoicesO, _MatrixTikTok))
					break;

				system("cls");
			}

			cout << endl << setw(52) << left << "";
			Answer = clsUtil::DoYouWantToContinue("Do You Want To Play More ? y/n ? ");

			if (Answer == 'Y' || Answer == 'y')
			{
				_RebuildTableGameTipTop(_MatrixTikTok);
				ChoicesX = ChoicesO = 0;
			}

		} while (Answer == 'Y' || Answer == 'y');
	}
};