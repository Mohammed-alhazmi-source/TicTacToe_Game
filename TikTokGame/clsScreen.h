#pragma once
#include <iostream>
#include <iomanip>
#include "TikTok.h"
#include "clsDate.h"
#include <string>

class clsScreen
{
private:
	static string _DateNow()
	{
		auto Date = clsDate::DateNow();
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	static void _PrintDate()
	{
		cout << setw(52) << left << "" << "------------------------------";
		cout << "\n" << setw(60) << left << "" << "Date : " << left << setw(30) << _DateNow();
		cout << "\n" << setw(52) << left << "" << "------------------------------";
	}
	static void _PrintWinName(const string& Name)
	{
		cout << setw(52) << left << "" << "------------------------------";
		cout << "\n" << setw(58) << left << "" << Name;
		cout << "\n" << setw(52) << left << "" << "------------------------------";
	}

public:

	static void _DrawHeaderScreen(string Title, string SubTitle = "")
	{
		cout << endl << endl;
		cout << setw(52) << left << "" << "==============================" << "\n";
		cout << setw(62) << left << "" << Title << "\n";
		
		if(SubTitle != "")
			cout << setw(63) << left << "" << SubTitle << "\n";

		cout << setw(52) << left << "" << "==============================";

		cout << endl;

		_PrintDate();

		cout << endl;
	}

	static void _RebuildTableGameTipTop (char _MatrixTikTok[3][3])
	{
		_MatrixTikTok[0][0] = '1';	_MatrixTikTok[0][1] = '2'; _MatrixTikTok[0][2] = '3';
		_MatrixTikTok[1][0] = '4';	_MatrixTikTok[1][1] = '5'; _MatrixTikTok[1][2] = '6';
		_MatrixTikTok[2][0] = '7';	_MatrixTikTok[2][1] = '8'; _MatrixTikTok[2][2] = '9';
	}

	static void _DrawTableGameTipTop(char _MatrixTikTok[3][3],const string &PlayersNames = "")
	{		
		_DrawHeaderScreen("Tik Tak Tok");
		_PrintWinName(PlayersNames);

		cout << endl;
		cout << setw(42) << left << "" << "=================================================";
		cout << endl << setw(42) << left << "" << "| ";
		cout << setw(6) << left << "" << _MatrixTikTok[0][0];
		cout << setw(6) << left << "" << " | ";
		cout << setw(6) << left << "" << _MatrixTikTok[0][1];
		cout << setw(6) << left << "" << " | ";
		cout << setw(6) << left << "" << _MatrixTikTok[0][2];
		cout << setw(6) << left << "" << " |";
		cout << endl << setw(42) << left << "" << "=================================================";
		cout << endl << setw(42) << left << "" << "| ";
		cout << setw(6) << left << "" << _MatrixTikTok[1][0];
		cout << setw(6) << left << "" << " | ";
		cout << setw(6) << left << "" << _MatrixTikTok[1][1];
		cout << setw(6) << left << "" << " | ";
		cout << setw(6) << left << "" << _MatrixTikTok[1][2];
		cout << setw(6) << left << "" << " |";
		cout << endl << setw(42) << left << "" << "=================================================";
		cout << endl << setw(42) << left << "" << "| ";
		cout << setw(6) << left << "" << _MatrixTikTok[2][0];
		cout << setw(6) << left << "" << " | ";
		cout << setw(6) << left << "" << _MatrixTikTok[2][1];
		cout << setw(6) << left << "" << " | ";
		cout << setw(6) << left << "" << _MatrixTikTok[2][2];
		cout << setw(6) << left << "" << " |";
		cout << endl << setw(42) << left << "" << "=================================================";
	}	

	static void _RefreshTableGameTipTop(char Choice, TikTok::enPlayers Player, char _MatrixTikTok[3][3])
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Choice == _MatrixTikTok[i][j])
				{
					if (Player == TikTok::enPlayers::PlayerX)
					{
						_MatrixTikTok[i][j] = 'X';
						break;
					}


					else if (Player == TikTok::enPlayers::PlayerO)
					{
						_MatrixTikTok[i][j] = 'O';
						break;
					}
				}
			}
		}
	}
};