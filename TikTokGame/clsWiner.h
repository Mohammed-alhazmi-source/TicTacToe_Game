#pragma once
#include "clsChoicePlayerValidate.h"
#include "clsReturn.h"
class clsWiner
{
	enum enWiners;

	static bool _IsGameEqual(short ChoiceX, short ChoiceO)
	{
		return (ChoiceX == 5 && ChoiceO == 4);
	}
	
	static enWiners _WinTheGame(enWiners Win)
	{
		if (Win == enWiners::Computer)
			return enWiners::Computer;

		else if (Win == enWiners::Player)
			return enWiners::Player;

		else if (Win == enWiners::NoWiner)
			return enWiners::NoWiner;

		return Win;
	}

	static enWiners _WhoTheWinGame(char _Matrix[3][3], short ChoicesX, short ChoicesO)
	{
		if (_IsGameEqual(ChoicesX, ChoicesO))
		{
			if (clsChoicePlayerValidate::_CheckOfChoicesPlayer('X', _Matrix))
				return enWiners::Player;

			else if (clsChoicePlayerValidate::_CheckOfChoicesPlayer('O', _Matrix))
				return enWiners::Computer;

			return enWiners::NoWiner;
		}

		else if (clsChoicePlayerValidate::_CheckOfChoicesPlayer('X', _Matrix))
			return enWiners::Player;

		else if (clsChoicePlayerValidate::_CheckOfChoicesPlayer('O', _Matrix))
			return enWiners::Computer;

		return enWiners::Continue;
	}

public:
	static enum enWiners { Player = 1, Computer = 2, NoWiner = 3, Continue = 4 };

	static enWiners _HasBeenWinGame(char _Matrix[3][3],short &ChoicesX, short &ChoicesO)
	{
		return _WinTheGame(_WhoTheWinGame(_Matrix, ChoicesX, ChoicesO));
	}
};

