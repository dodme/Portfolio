#include "DoubleBuffer.h"

int main()
{
	int play = 0;
	char Maze[40][42] = { 0 };
	char Map[40][42] = { 0 };

	Player* player = new Player();

#pragma region Start
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "       ■■■■■■■■■    ■■■■■    ■■■■■■■   ■■■■■■" << endl;
	cout << "       ■      ■      ■    ■      ■                ■   ■" << endl;
	cout << "       ■      ■      ■    ■      ■              ■     ■" << endl;
	cout << "       ■      ■      ■    ■      ■            ■       ■" << endl;
	cout << "       ■      ■      ■    ■■■■■          ■         ■■■■■■" << endl;
	cout << "       ■      ■      ■    ■      ■        ■           ■" << endl;
	cout << "       ■      ■      ■    ■      ■      ■             ■" << endl;
	cout << "       ■      ■      ■    ■      ■    ■               ■" << endl;
	cout << "       ■      ■      ■    ■      ■    ■■■■■■■   ■■■■■■" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "                               w : 위로 이동" << endl;
	cout << "                               s : 아래로 이동" << endl;
	cout << "                               d : 오른쪽로 이동" << endl;
	cout << "                               a : 왼쪽로 이동" << endl;
	cout << "                               m : 지도 열기/닫기" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "                               ▣ : 시작지점" << endl;
	cout << "                               ★ : 도착지점" << endl;
	cout << "                               § : 열쇠" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "                       시작하려면 아무 키나 누르세요..." << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

#pragma endregion

	if (_getch())
	{
		system("cls");
		CreateBuffer();

		SetMaze(Maze);
		SetMap(Map);

		while (true)
		{
			Render(player, Maze, Map);

			if (Maze[player->GetVector()->GetY()][player->GetVector()->GetX()] == Maze[38][39] &&
				player->GetIsGetKey())
			{
#pragma region 데이터누수 다메다요
				DeleteBuffer();
				delete player;
				player = nullptr;
#pragma endregion
#pragma region Clear!
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
				cout << "■          ■■  ■■■■■■          ■■■        ■■■        ■■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■            ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■          ■■  ■■■■  ■■        ■■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■  ■■■■■■  ■■■■■■  ■■■■■■  ■■■■  ■■  ■■■  ■■■■■■" << endl;
				cout << "■          ■■          ■■          ■■  ■■■■  ■■  ■■■  ■■■  ■■" << endl;
				cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
				cout << "                                          " << endl;
#pragma endregion
				break;
			}
		}
	}


	return 0;
}