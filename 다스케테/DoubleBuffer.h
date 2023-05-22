#pragma once
#include "Header.h"
#include "Map.h"

#define SCREEN_WIDTH 84
#define SCREEN_HEIGHT 42

static HANDLE ScreenBuffer[2];
static int screenIndex;

#pragma region Vector
struct Vector2D
{
private :
	int x;
	int y;

public  :
	Vector2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void SetVector(int x, int y) { this->x = x; this->y = y; }

	int GetX() { return x; }
	int GetY() { return y; }
};
#pragma endregion

#pragma region Player

enum Direction
{
	Up,
	Down,
	Right,
	Left,
};

class Player
{
private:
	// TODO 열쇠체크, Player Die 구현
	char* playerChar = nullptr;
	Vector2D* playerVec = nullptr;
	Direction dir;
	int sight;
	bool isGetKey;

public:
	Player()
	{
		playerChar = new char[128];
		playerVec = new Vector2D(1, 1);
		dir = Direction::Down;
		SetDirection();
		sight = 2;
		isGetKey = false;
	}

	Vector2D* GetVector() { return playerVec; }

	void PlayerInputKey(char Maze[40][42], char Map[40][42]);
	// 지나온길에 원래대로 맵을 출력
	void AfterMovement(char Maze[40][42]);
	void InTrap(char Maze[40][42]);

	void SetDirection();
	void SightUp();
	void SetIsGetKey();

	int GetDir() { return dir; }
	char* GetPlayerChar() { return playerChar; }
	int GetSight() { return sight; }
	bool GetIsGetKey() { return isGetKey; }

	~Player()
	{
		delete playerVec;
		playerVec = nullptr;
		delete[] playerChar;
		playerChar = nullptr;
	}
};

#pragma endregion

void CreateBuffer();
void ClearBuffer();
void ScreenTransform();
void DeleteBuffer();
void ScreenPrintPlayer(Player* player);
void ScreenPrintMaze(int x, int y, const char* str);
void DrawMap(Player* player, char Map[40][42]);
void Render(Player* player, char Maze[40][42], char Map[40][42]);