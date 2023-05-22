#include "DoubleBuffer.h"

void CreateBuffer()
{
	ScreenBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CONSOLE_CURSOR_INFO cci = { 0 };

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(ScreenBuffer[0], &cci);
	SetConsoleCursorInfo(ScreenBuffer[1], &cci);
}

void ClearBuffer()
{
	COORD cd = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(ScreenBuffer[screenIndex], ' ', SCREEN_WIDTH * SCREEN_HEIGHT, cd, &dw);
}

void ScreenTransform()
{
	SetConsoleActiveScreenBuffer(ScreenBuffer[screenIndex]);
	screenIndex = !screenIndex;
}

void DeleteBuffer()
{
	CloseHandle(ScreenBuffer[0]);
	CloseHandle(ScreenBuffer[1]);
}

void ScreenPrintPlayer(Player* player)
{
	DWORD dw;
	COORD CursorPosition = { player->GetVector()->GetX() * 2, player->GetVector()->GetY() };

	SetConsoleCursorPosition(ScreenBuffer[screenIndex], CursorPosition);
	WriteFile(ScreenBuffer[screenIndex], player->GetPlayerChar(), strlen(player->GetPlayerChar()), &dw, NULL);
}

void ScreenPrintMaze(int x, int y, const char* str)
{
	DWORD dw;
	COORD CursorPosition = { x * 2, y };

	SetConsoleCursorPosition(ScreenBuffer[screenIndex], CursorPosition);
	WriteFile(ScreenBuffer[screenIndex], str, strlen(str), &dw, NULL);
}

void DrawMap(Player* player, char Map[40][42])
{
	if (Map[player->GetVector()->GetX()][player->GetVector()->GetY()] == Map[1][1])
		Map[player->GetVector()->GetX()][player->GetVector()->GetY()] = '2';
	else if ((player->GetVector()->GetX() == 6 && player->GetVector()->GetY() == 7) ||
		(player->GetVector()->GetX() == 10 && player->GetVector()->GetY() == 19) ||
		(player->GetVector()->GetX() == 22 && player->GetVector()->GetY() == 23) ||
		(player->GetVector()->GetX() == 21 && player->GetVector()->GetY() == 28) ||
		(player->GetVector()->GetX() == 38 && player->GetVector()->GetY() == 18) ||
		(player->GetVector()->GetX() == 38 && player->GetVector()->GetY() == 38) ||
		(player->GetVector()->GetX() == 11 && player->GetVector()->GetY() == 38))
		Map[player->GetVector()->GetX()][player->GetVector()->GetY()] = '4';
	else if (Map[player->GetVector()->GetX()][player->GetVector()->GetY()] == Map[39][38])
		Map[player->GetVector()->GetX()][player->GetVector()->GetY()] = '3';
	else
		Map[player->GetVector()->GetX()][player->GetVector()->GetY()] = '1';
}

void Render(Player* player, char Maze[40][42], char Map[40][42])
{
	//ScreenPrintMaze(0, 0, "");
	ClearBuffer();


	player->PlayerInputKey(Maze, Map);

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 42; j++)
		{
			if ((player->GetVector()->GetX() - player->GetSight()) <= j &&
				(player->GetVector()->GetX() + player->GetSight()) >= j &&
				(player->GetVector()->GetY() - player->GetSight()) <= i &&
				(player->GetVector()->GetY() + player->GetSight()) >= i)
			{
				switch ((int)Maze[i][j])
				{
				case 48:
					ScreenPrintMaze(j, i, "■");
					break;

				case 104:
					ScreenPrintMaze(j, i, "■");
					break;

				case 49:
					ScreenPrintMaze(j, i, "  ");
					break;

				case 50:
					ScreenPrintMaze(j, i, "▣");
					break;

				case 51:
					ScreenPrintMaze(j, i, "★");
					break;

				case 52:
					ScreenPrintMaze(j, i, "  ");
					break;

				case 105:
					ScreenPrintMaze(j, i, "※");
					break;

				case 107:
					ScreenPrintMaze(j, i, "§");
					break;

				case 112:
					ScreenPrintPlayer(player);
					break;
				}
			}
		}
	}

	if (player->GetVector()->GetX() == 21 && player->GetVector()->GetY() == 24)
		player->SightUp();

	if (player->GetVector()->GetX() == 22 && player->GetVector()->GetY() == 28)
		player->SetIsGetKey();

	DrawMap(player, Map);
	player->InTrap(Maze);


	Sleep(10);
	//ScreenPrintMaze(0, 0, "");

	DWORD dw;
	COORD CursorPosition = { 0, 0 };

	SetConsoleCursorPosition(ScreenBuffer[screenIndex], CursorPosition);

	ScreenTransform();
}

#pragma region Player

void Player::PlayerInputKey(char Maze[40][42], char Map[40][42])
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			dir = Direction::Up;
			SetDirection();
			if (playerVec->GetY() - 1 >= 1)
			{
				if (Maze[playerVec->GetY() - 1][playerVec->GetX()] != '0')
				{
					AfterMovement(Maze);
					Maze[playerVec->GetY() - 1][playerVec->GetX()] = 'p';
					playerVec->SetVector(playerVec->GetX(), playerVec->GetY() - 1);
				}
			}
			break;

		case 's':
			dir = Direction::Down;
			SetDirection();
			if (playerVec->GetY() + 1 < SCREEN_HEIGHT)
			{
				if (Maze[playerVec->GetY() + 1][playerVec->GetX()] != '0')
				{
					AfterMovement(Maze);
					Maze[playerVec->GetY() + 1][playerVec->GetX()] = 'p';
					playerVec->SetVector(playerVec->GetX(), playerVec->GetY() + 1);
				}
			}
			break;

		case 'a':
			dir = Direction::Left;
			SetDirection();
			if (playerVec->GetX() - 1 >= 1)
			{
				if (Maze[playerVec->GetY()][playerVec->GetX() - 1] != '0')
				{
					AfterMovement(Maze);
					Maze[playerVec->GetY()][playerVec->GetX() - 1] = 'p';
					playerVec->SetVector(playerVec->GetX() - 1, playerVec->GetY());
				}
			}
			break;

		case 'd':
			dir = Direction::Right;
			SetDirection();
			if (playerVec->GetX() + 1 < SCREEN_WIDTH)
			{
				if (Maze[playerVec->GetY()][playerVec->GetX() + 1] != '0')
				{
					AfterMovement(Maze);
					Maze[playerVec->GetY()][playerVec->GetX() + 1] = 'p';
					playerVec->SetVector(playerVec->GetX() + 1, playerVec->GetY());
				}
			}
			break;

		case 'm':
			DeleteBuffer();
			CreateBuffer();
			ClearBuffer();
			for (int i = 0; i < 40; i++)
			{
				for (int j = 0; j < 42; j++)
				{
					switch ((int)Map[j][i])
					{
					case 48:
						ScreenPrintMaze(j, i, "■");
						break;

					case 49:
						ScreenPrintMaze(j, i, "  ");
						break;

					case 50:
						ScreenPrintMaze(j, i, "▣");
						break;

					case 51:
						ScreenPrintMaze(j, i, "★");
						break;

					case 52:
						ScreenPrintMaze(j, i, "×");
						break;
					}
				}
			}

			Sleep(10);

			ScreenTransform();
			if (_kbhit)
			{
				if (_getch())
				{
					DeleteBuffer();
					CreateBuffer();
					break;
				}
			}

		}
	}
}

void Player::AfterMovement(char Maze[40][42])
{
	if (Maze[playerVec->GetY()][playerVec->GetX()] == Maze[1][1])
		Maze[playerVec->GetY()][playerVec->GetX()] = '2';
	else if (Maze[playerVec->GetY()][playerVec->GetX()] == Maze[21][10])
		Maze[playerVec->GetY()][playerVec->GetX()] = 'h';
	else if (Maze[playerVec->GetY()][playerVec->GetX()] == Maze[38][39])
		Maze[playerVec->GetY()][playerVec->GetX()] = '3';
	else
		Maze[playerVec->GetY()][playerVec->GetX()] = '1';
}

void Player::InTrap(char Maze[40][42])
{
	if ((playerVec->GetX() == 6 && playerVec->GetY() == 7) ||
		(playerVec->GetX() == 10 && playerVec->GetY() == 19) ||
		(playerVec->GetX() == 22 && playerVec->GetY() == 23) ||
		(playerVec->GetX() == 21 && playerVec->GetY() == 28) ||
		(playerVec->GetX() == 38 && playerVec->GetY() == 18) ||
		(playerVec->GetX() == 38 && playerVec->GetY() == 38) ||
		(playerVec->GetX() == 11 && playerVec->GetY() == 38))
	{
		DeleteBuffer();
		CreateBuffer();
		ClearBuffer();
		ScreenPrintMaze(16, 20, "함정에 빠졌습니다!");
		playerVec->SetVector(1, 1);
		Maze[1][1] = 'p';
		ScreenTransform();
		Sleep(3000);
		DeleteBuffer();
		CreateBuffer();
	}
}

void Player::SetDirection()
{
	switch (dir)
	{
	case Up:
		strcpy(playerChar, "▲");
		break;

	case Down:
		strcpy(playerChar, "▼");
		break;

	case Left:
		strcpy(playerChar, "◀");
		break;

	case Right:
		strcpy(playerChar, "▶");
		break;

	}
}
void Player::SightUp()
{
	sight = 3;
}
void Player::SetIsGetKey()
{
	isGetKey = true;
}
#pragma endregion