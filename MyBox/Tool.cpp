#include "pch.h"
#include "Tool.h"

Tool::Tool(int type)
{
	_type = type;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			_data[i][j] = 0;
	switch (_type)
	{
	case 1:
		_data[1][0] = _data[1][1] = _data[1][2] = _data[1][3] = 1;
		break;
	case 2:
		_data[1][1] = _data[1][2] = _data[2][1] = _data[2][2] = 2;
		break;
	case 3:
		_data[1][1] = _data[1][2] = _data[2][1] = _data[3][1] = 3;
		break;
	case 4:
		_data[1][0] = _data[1][1] = _data[2][1] = _data[3][1] = 4;
		break;
	case 5:
		_data[1][0] = _data[1][1] = _data[2][1] = _data[2][2] = 5;
		break;
	case 6:
		_data[1][1] = _data[2][0] = _data[2][1] = _data[2][2] = 6;
		break;
	case 7:
		_data[2][0] = _data[2][1] = _data[1][1] = _data[1][2] = 7;
		break;
	case 8:
		_data[0][1] = _data[1][0] = _data[1][2] = _data[2][1] = 8;
		break;
	case 9:
		_data[1][0] = _data[2][1] = _data[2][2] = _data[1][3] = 9;
		break;
	case 10:
		_data[0][0] = _data[1][1] = _data[2][2] = _data[3][3] = 10;
		break;
	case 11:
		_data[1][0] = _data[2][1] = _data[3][2] = _data[1][2] = 11;
		break;
	case 12:
		_data[1][0] = _data[1][2] = _data[2][1] = _data[3][1] = 12;
		break;
	}
}
const int Tool::GetType() const
{
	return _type;
}
const int& Tool::ElementAt(int i, int j) const
{
	return _data[i][j];
}
Tool Tool::Roll()
{
	Tool rolled_tool(*this);
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			rolled_tool._data[i][j] = _data[3 - j][i];
	return rolled_tool;
}