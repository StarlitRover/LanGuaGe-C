#include "pch.h"
#include "Game.h"
Game::Game(int height, int width) :_tool(0), _nextTool(0), _score(0), _level(1),_interval(500)
{
	_netWidth = width;
	_netHeight = height;
	_bigNet = _bigNetAux = nullptr;
	_state = STOP;

	_bigNet = new int[_netHeight * _netWidth];
	_bigNetAux = new int[_netHeight * _netWidth];
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			_bigNet[i * _netWidth + j] = 0;
	srand((unsigned int)time(0));
}
Game::~Game(void)
{
	delete[] _bigNet;
	delete[] _bigNetAux;
}
void Game::Start()
{
	_state = GO;
	_interval = 500;
	_score = 0;
	_level = 1;
	for (int i = 0; i < _netHeight; ++i)
		for (int j = 0; j < _netWidth; ++j)
			_bigNet[i * _netWidth + j] = 0;
	NextTool();
	NextTool();
}
void Game::NextTool()
{
	_iLocX = (_netWidth - 4) / 2;
	_iLocY = 0;
	_tool = _nextTool;
	_nextTool = Tool(rand() % 12 + 1);
}

bool Game::CanMoveDown()
{
	int cnt1 = 4, cnt2 = 0;
	cnt1 += CountNoneZero(_bigNet, _netHeight, _netWidth);
	AddToolToAux(_bigNetAux, _iLocX, _iLocY + 1, _tool);
	cnt2 = CountNoneZero(_bigNetAux, _netHeight, _netWidth);
	return cnt1 == cnt2;
}

int Game::CountNoneZero(int* matrix, int Height, int Width)
{
	int cnt = 0;
	for (int i = 0; i < Height; ++i)
		for (int j = 0; j < Width; ++j)
			if (matrix[i * Width + j])
				++cnt;
	return cnt;
}

void Game::AddToolToAux(int* net, int iOffsetX, int iOffsetY, const Tool& _tool)
{
	if (net != _bigNet)
		for (int i = 0; i < _netHeight; ++i)
			for (int j = 0; j < _netWidth; ++j)
				net[i * _netWidth + j] = _bigNet[i * _netWidth + j];
	int iType = _tool.GetType();
	if (iType != 0) 
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) 
			{
				if (_tool.ElementAt(i, j) != 0 && i + iOffsetY >= 0 &&
					i + iOffsetY < _netHeight && j + iOffsetX >= 0 &&
					j + iOffsetX < _netWidth)
					net[(i + iOffsetY) * _netWidth + j + iOffsetX] = iType;
			}
}

void Game::MoveDown()
{
	++_iLocY;
}

bool Game::CanMoveLeft()
{
	int cnt1 = 4, cnt2 = 0;
	cnt1 += CountNoneZero(_bigNet, _netHeight, _netWidth);
	AddToolToAux(_bigNetAux, _iLocX - 1, _iLocY, _tool); 
	cnt2 = CountNoneZero(_bigNetAux, _netHeight, _netWidth);
	return cnt2 == cnt1;
}

bool Game::CanMoveRight()
{
	int cnt1 = 4, cnt2 = 0;
	cnt1 += CountNoneZero(_bigNet, _netHeight, _netWidth);
	AddToolToAux(_bigNetAux, _iLocX + 1, _iLocY, _tool);
	cnt2 = CountNoneZero(_bigNetAux, _netHeight, _netWidth);
	return cnt2 == cnt1;
}

void Game::MoveLeft()
{
	--_iLocX;
}

void Game::MoveRight()
{
	++_iLocX;
}

bool Game::CanRoll()
{
	int cnt1 = 4, cnt2 = 0;
	cnt1 += CountNoneZero(_bigNet, _netHeight, _netWidth);
	Tool  toolRotated = _tool.Roll();
	AddToolToAux(_bigNetAux, _iLocX, _iLocY, toolRotated);
	cnt2 = CountNoneZero(_bigNetAux, _netHeight, _netWidth);
	return cnt2 == cnt1;
}

void Game::Roll() 
{
	_tool = _tool.Roll();
}

void Game::Input(UINT nChar)
{
	switch (nChar) 
	{
	case VK_UP: if (CanRoll()) Roll();break;
	case VK_DOWN: if (CanMoveDown()) MoveDown(); break;
	case VK_LEFT: if (CanMoveLeft()) MoveLeft(); break;
	case VK_RIGHT: if (CanMoveRight()) MoveRight(); break;
	}
}

bool Game::Go()
{
	if (CanMoveDown()) 
	{
		MoveDown();
		return true;
	}
	else 
	{
		AddToolToAux(_bigNet, _iLocX, _iLocY, _tool);//注意这里的_bigNet为真正的游戏主界面
		RemoveLines();
		NextTool();
		if (IsDead()) 
		{
			_state = STOP;
			return false;
		}
		return true;
	}
}

void Game::RemoveLines()
{
	for (int i = _netHeight - 1; i >= 0; i--)
	{
		int cnt = 1;
		while (CanRemoveLine(i))
		{
			_score += cnt * 100;
			_level = _score / 500 + 1;
			RemoveLine(i);
			++cnt;
		}
	}
}

bool Game::CanRemoveLine(int index)
{
	int count = 0;
	for (int i = 0; i < _netWidth; i++)
		if (_bigNet[index * _netWidth + i] != 0)
			count++;
	//return count == _netWidth;
	return count >= _netWidth - 2 && count <= _netWidth;
}

void Game::RemoveLine(int index)
{
	for (int i = index; i > 0; i--)
		for (int j = 0; j < _netWidth; j++)
			_bigNet[i * _netWidth + j] = _bigNet[(i - 1) * _netWidth + j];
	for (int j = 0; j < _netWidth; j++)
		_bigNet[j] = 0;
}

bool Game::IsDead()
{
	int cnt1 = 4, cnt2 = 0;
	cnt1 += CountNoneZero(_bigNet, _netHeight, _netWidth);
	AddToolToAux(_bigNetAux, _iLocX, _iLocY, _tool);
	cnt2 = CountNoneZero(_bigNetAux, _netHeight, _netWidth);
	return cnt2 != cnt1;
}

void Game::PauseOrContinue()
{
	if (_state == PAUSE)
		_state = GO;
	else if (_state == GO)
		_state = PAUSE;
}
