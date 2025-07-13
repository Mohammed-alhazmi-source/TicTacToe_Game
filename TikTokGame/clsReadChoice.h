#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsChoiceValid.h"
#include "clsRandomNumber.h"
using namespace std;

class clsReadChoice
{
public:
	static char _ReadChoicePlayerX(char _Matrix[3][3], short &ChoicesPlayerX)
	{
		char Choice;

		do
		{
			cout << "\n" << setw(63) << left << "" << "PlayerX : ";
			Choice = clsInputValidate::ReadNumberBetween(1, 9) + '0';
		} while (!clsChoiceValid::_IsChoiceValid(Choice,_Matrix));
		ChoicesPlayerX++;
		return Choice;
	}

	static char _ReadChoicePlayerO(char _Matrix[3][3], short& ChoicesPlayerO)
	{
		char Choice;

		do
		{
			cout << "\n" << setw(63) << left << "" << "PlayerO : ";
			Choice = clsInputValidate::ReadNumberBetween(1, 9) + '0';
		} while (!clsChoiceValid::_IsChoiceValid(Choice, _Matrix));
		ChoicesPlayerO++;
		return Choice;
	}

	static char _ReadChoiceComputer(char _Matrix[3][3], short &ChoicesComputer)
	{
		char Choice;

		do
		{
			Choice = (clsRandomNumber::_RandomNumber(1, 9) + '0');
		} while (!clsChoiceValid::_IsChoiceValid(Choice,_Matrix));

		//cout << Choice - '0' << endl;
		ChoicesComputer++;
		return Choice;
	}
};