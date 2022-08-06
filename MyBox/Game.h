#pragma once
#include"Tool.h"
enum GAME_STATE
{
	PAUSE,
	GO,
	STOP
};
class Game
{
	friend class CMyBoxDlg;
private:
	GAME_STATE _state;
	int* _bigNet;
	int* _bigNetAux;
	int _netWidth, _netHeight;
	Tool _tool;
	Tool _nextTool;
	int _iLocX, _iLocY;
	int _score, _level,_interval;

public:
	Game(int height, int width);
	~Game(void);
	void Start();
	void Input(UINT nChar);
private:
	void NextTool();
	bool CanMoveDown();
	int CountNoneZero(int* matrix, int Height, int Width);
	void AddToolToAux(int* net, int iOffsetX, int iOffsetY, const Tool& _tool);
	void MoveDown();
	bool CanMoveLeft();
	bool CanMoveRight();
	void MoveLeft();
	void MoveRight();
	bool CanRoll();
	void Roll();
	bool Go();
	void RemoveLines();
	bool CanRemoveLine(int index);
	void RemoveLine(int index);
	bool IsDead();
	void PauseOrContinue();
};

