#pragma once
class clsFindIndexItem
{
public:
	static enum enItemsIndies
	{
		OneItemIndex = '1', TwoItemIndex = '2', ThreeItemIndex = '3', FourItemIndex = '4',
		FiveItemIndex = '5', SixItemIndex = '6', SevenItemIndex = '7', EightItemIndex = '8',
		NineItemIndex = '9'
	};


	static void _IndexItem(enItemsIndies IndexItem, short& Row, short& Col)
	{
		switch (IndexItem)
		{
		case enItemsIndies::OneItemIndex:
			Row = Col = 0;
			break;

		case enItemsIndies::TwoItemIndex:
			Row = 0; Col = 1;
			break;

		case enItemsIndies::ThreeItemIndex:
			Row = 0; Col = 2;
			break;

		case enItemsIndies::FourItemIndex:
			Row = 1; Col = 0;
			break;

		case enItemsIndies::FiveItemIndex:
			Row = Col = 1;
			break;

		case enItemsIndies::SixItemIndex:
			Row = 1; Col = 2;
			break;

		case enItemsIndies::SevenItemIndex:
			Row = 2; Col = 0;
			break;

		case enItemsIndies::EightItemIndex:
			Row = 2; Col = 1;
			break;

		case enItemsIndies::NineItemIndex:
			Row = Col = 2;
			break;
		}
	}
};

