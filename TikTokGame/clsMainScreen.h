#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsPlayYourSelfScreen.h"
#include "clsPlayWithComputerScreen.h"

class clsMainScreen : protected clsScreen
{
private:
	enum enMainOptions { PlayYourSelf = 1, PlayWithComputer = 2, Exit = 3 };

	static short _ReadOption()
	{
		return clsUtil::ReadOption(1, 3);
	}

	static void _GoBackToMainMenu()
	{
		system("pause");
		system("Color 0F");
		ShowMainMenu();
	}

	static void _ShowPlayYourSelfScreen()
	{
		clsPlayYourSelfScreen::StartGame();
	}

	static void _ShowPlayWithComputerScreen()
	{
		clsPlayWithComputerScreen::StartGame();
	}

	static void _Exit()
	{
		cout << endl << "--------------------------------------";
		cout << "\nEnd Program :-)";
		cout << endl << "--------------------------------------\n";
	}

	static void _ExecuteTheSelectedOption(enMainOptions Option)
	{
		switch (Option)
		{
		case clsMainScreen::PlayYourSelf:
		{
			system("cls");
			_ShowPlayYourSelfScreen();
			_GoBackToMainMenu();
			break;
		}

		case clsMainScreen::PlayWithComputer:
		{
			system("cls");
			_ShowPlayWithComputerScreen();
			_GoBackToMainMenu();
			break;
		}

		case clsMainScreen::Exit:
		{
			system("cls");
			_Exit();
			break;
		}
		}
	}

	static void _PrintMainMenu()
	{
		cout << "\n" << setw(52) << left << "" << "======================================";
		cout << "\n" << setw(52) << left << "" << "Enter <1> Play Your Self.";
		cout << "\n" << setw(52) << left << "" << "Enter <2> Play With Computer.";
		cout << "\n" << setw(52) << left << "" << "Enter <3> Exit.";
		cout << "\n" << setw(52) << left << "" << "======================================";
	}

public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawHeaderScreen("Tic Tac Toe");
		_PrintMainMenu();
		_ExecuteTheSelectedOption((enMainOptions)_ReadOption());
	}
};