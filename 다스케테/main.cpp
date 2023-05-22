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
	cout << "       ����������    ������    ��������   �������" << endl;
	cout << "       ��      ��      ��    ��      ��                ��   ��" << endl;
	cout << "       ��      ��      ��    ��      ��              ��     ��" << endl;
	cout << "       ��      ��      ��    ��      ��            ��       ��" << endl;
	cout << "       ��      ��      ��    ������          ��         �������" << endl;
	cout << "       ��      ��      ��    ��      ��        ��           ��" << endl;
	cout << "       ��      ��      ��    ��      ��      ��             ��" << endl;
	cout << "       ��      ��      ��    ��      ��    ��               ��" << endl;
	cout << "       ��      ��      ��    ��      ��    ��������   �������" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "                               w : ���� �̵�" << endl;
	cout << "                               s : �Ʒ��� �̵�" << endl;
	cout << "                               d : �����ʷ� �̵�" << endl;
	cout << "                               a : ���ʷ� �̵�" << endl;
	cout << "                               m : ���� ����/�ݱ�" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "                               �� : ��������" << endl;
	cout << "                               �� : ��������" << endl;
	cout << "                               �� : ����" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "                       �����Ϸ��� �ƹ� Ű�� ��������..." << endl;
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
#pragma region �����ʹ��� �ٸ޴ٿ�
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
				cout << "������������������������������������������" << endl;
				cout << "��          ���  �������          ����        ����        �����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������            ���  ����  ����  ���" << endl;
				cout << "��  �������  �������          ���  �����  ���        �����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  ����  ���" << endl;
				cout << "��  �������  �������  �������  �����  ���  ����  �������" << endl;
				cout << "��          ���          ���          ���  �����  ���  ����  ����  ���" << endl;
				cout << "������������������������������������������" << endl;
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