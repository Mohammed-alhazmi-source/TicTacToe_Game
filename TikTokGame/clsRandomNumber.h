#pragma once
#include <iostream>
using namespace std;

class clsRandomNumber
{
public:
	static short _RandomNumber(short From, short To)
	{
		return (rand() % (From + To - From) + From);
	}
};

