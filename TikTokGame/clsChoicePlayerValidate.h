#pragma once
class clsChoicePlayerValidate
{
	static bool _FirstTheRowItems(char Choice, char _MatrixTikTok[3][3])
	{
		return (_MatrixTikTok[0][0] == Choice && _MatrixTikTok[0][1] == Choice && _MatrixTikTok[0][2] == Choice);
	}

	static bool _SecondTheRowItems(char Choice, char _MatrixTikTok[3][3])
	{
		return (_MatrixTikTok[1][0] == Choice && _MatrixTikTok[1][1] == Choice && _MatrixTikTok[1][2] == Choice);
	}

	static bool _ThirdTheRowItems(char Choice, char _MatrixTikTok[3][3])
	{
		return (_MatrixTikTok[2][0] == Choice && _MatrixTikTok[2][1] == Choice && _MatrixTikTok[2][2] == Choice);
	}

	static bool _FirstTheColumnItems(char Choice, char _MatrixTikTok[3][3])
	{
		return (_MatrixTikTok[0][0] == Choice && _MatrixTikTok[1][0] == Choice && _MatrixTikTok[2][0] == Choice);
	}

	static bool _SecondTheColumnItems(char Choice, char _MatrixTikTok[3][3])
	{
		return (_MatrixTikTok[0][1] == Choice && _MatrixTikTok[1][1] == Choice && _MatrixTikTok[2][1] == Choice);
	}

	static bool _ThirdTheColumnItems(char Choice, char _MatrixTikTok[3][3])
	{
		return (_MatrixTikTok[0][2] == Choice && _MatrixTikTok[1][2] == Choice && _MatrixTikTok[2][2] == Choice);
	}

	static bool _BaseQuoterItems(char Choice, char _MatrixTikTok[3][3])
	{
		return (_MatrixTikTok[0][0] == Choice && _MatrixTikTok[1][1] == Choice && _MatrixTikTok[2][2] == Choice);
	}

	static bool _SecondaryQuoterItems(char Choice,char _MatrixTikTok[3][3])
	{
		return (_MatrixTikTok[0][2] == Choice && _MatrixTikTok[1][1] == Choice && _MatrixTikTok[2][0] == Choice);
	}


public:
	static bool _CheckOfChoicesPlayer(char Choice, char _MatrixTikTok[3][3])
	{
		if (_FirstTheRowItems(Choice, _MatrixTikTok))
			return true;

		else if (_SecondTheRowItems(Choice, _MatrixTikTok))
			return true;

		else if (_ThirdTheRowItems(Choice, _MatrixTikTok))
			return true;

		else if (_FirstTheColumnItems(Choice, _MatrixTikTok))
			return true;

		else if (_SecondTheColumnItems(Choice, _MatrixTikTok))
			return true;

		else if (_ThirdTheColumnItems(Choice, _MatrixTikTok))
			return true;

		else if (_BaseQuoterItems(Choice, _MatrixTikTok))
			return true;

		else if (_SecondaryQuoterItems(Choice, _MatrixTikTok))
			return true;

		return false;
	}
};