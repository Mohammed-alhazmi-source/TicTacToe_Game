#pragma once
#include "clsFindIndexItem.h"
class clsChoiceValid
{
public:
	static bool _IsChoiceValid(char Choice,char _MatrixTikTok[3][3])
	{
		short Row = 0, Col = 0;
		clsFindIndexItem::_IndexItem((clsFindIndexItem::enItemsIndies)Choice, Row, Col);

		if (_MatrixTikTok[Row][Col] == Choice)
			return true;

		return false;
	}
};

