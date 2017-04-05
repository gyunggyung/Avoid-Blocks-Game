#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "input_output.h"
#include <mmsystem.h>
using namespace std;
#define X_MAX 26	//����ĭ��
#define SPACE 25
void node_down();
int c = rand() % (X_MAX - 1) + 3;

void clearscreen();  //ȭ�� �ø�Ŀ ����

char map[60][X_MAX];
char obstacle = 'O'; //���
int	 a = 0, b = rand() % (X_MAX - 1) + 3;			//��� ��ǥ
int y = 18, x = 9;									//����   ��ǥ

int main()
{
	string name;
	int deathcounter = 0;
	//�� ����
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < X_MAX; ++j) {
			map[i + SPACE][0] = '|';
			map[i + SPACE][X_MAX - 2] = '|';
			map[i + SPACE][j] = ' ';
		}
	}

	srand(time(0));

	int points = 0;
	int speed = 100;					//���, ���� ���ǵ�
	int cashcheck = 0;					//ĳ��
	int cashpickedup = 0;				//�� ������ ++
	bool startup = true;
	int point = 0;


	char car = 'X';
	map[y + SPACE][x] = car;

	PlaySound(TEXT("123.wav"), NULL, SND_FILENAME | SND_ASYNC );  //���� ��� �ϸ鼭 �������� 
	//������ ����

	for (;;) {
		clearscreen(); //ȭ�� �ø�Ŀ ����
					   //�÷��̾�
		map[y + SPACE][x] = 'X';
		map[y + SPACE][x + 1] = '|';
		map[y + SPACE][x - 1] = '|';

		//��� ��������
		node_down();

		//ȭ�� ���
		for (int i = 0; i < 20; ++i) {
			for (int j = 0; j < X_MAX; ++j) {
				cout << map[i + SPACE][j];
				if (j >= X_MAX - 1) {
					cout << endl;
				}
			}
		}//���� ���
		point = deathcounter + (cashpickedup * 10);
		cout << "Points: " << point << "        Deathcounter: " << deathcounter << "\n";
		cout << "\nDeathcounter�� 2000�� �Ǹ� ����ʴϴ�. ";

		//��������
		if (deathcounter == 2000)
		{
			cout << "\n\n�̸��� �Է��ϼ���\n" << endl;
			cin >> name;
			system("cls");
			user_input_output(name, point);
			cin.get();
			return 0;
		}

		if (startup) {
			_getch(); //Ű �ޱ�
			startup = false;
		}

		//���� �̵�
		if (GetAsyncKeyState(VK_LEFT)) {
			if (map[y + SPACE][x - 3] == obstacle) {
				goto lost;		//������
			}
			else if (map[y + SPACE][x - 3] != '|') {
				//�� ������ ������ ������ ���
				map[y + SPACE][x] = ' ';
				map[y + SPACE][x + 1] = ' ';
				map[y + SPACE][x - 1] = ' ';

				x -= 3;
				map[y + SPACE][x] = 'X';
				map[y + SPACE][x + 1] = '|';
				map[y + SPACE][x - 1] = '|';

			}
		}

		//������ �̵�
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (map[y + SPACE][x + 3] == obstacle) {
				goto lost;		//������
			}
			else if (map[y + SPACE][x + 3] != '|') {
				//�� ������ ������ ������ ���
				map[y + SPACE][x] = ' ';
				map[y + SPACE][x + 1] = ' ';
				map[y + SPACE][x - 1] = ' ';

				x += 3;
				map[y + SPACE][x] = 'X';
				map[y + SPACE][x + 1] = '|';
				map[y + SPACE][x - 1] = '|';

			}
		}

		//���� ������
		if (map[y + SPACE][x] == obstacle || map[y + SPACE][x - 1] == obstacle || map[y + SPACE][x + 1] == obstacle) {
		lost:
			++cashpickedup;
		}

		deathcounter++;

		//�ӵ� ���
		if (deathcounter == 100 || deathcounter == 200 || deathcounter == 300 || deathcounter == 400 || deathcounter == 500) {
			speed -= 18;
		}
		if (deathcounter == 1000)
			speed -= 8;
		if (deathcounter == 1800)
			speed -= 2;
		Sleep(speed);
	}
	return 0;

}
void clearscreen()
{
	HANDLE hOut;	//void ������ ������ ����
	COORD Position;	//��ǥ �޴� ����ü

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//������ ��

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);	//Ŀ�� �̵���
												//�ڵ� ���� ù����� �ް�, �ι�°�� Ŀ���� �̵��ϰ��� �ϴ� ��ǥ���� ������ ���� ����ü COORD�� �޴´�.
}	//ȭ�� �����̴°� ����

void node_down()
{
	int node_num = 10;
	for (int j = 0; j < node_num; j++)
	{
		map[a - j + SPACE][b] = ' ';
		map[a - j + SPACE][b + 1] = ' ';
		map[a - j + SPACE][b - 1] = ' ';
	}
	++a;
	//��� ����
	for (int j = 0; j < node_num; j++)
	{
		map[a - j + SPACE][b] = obstacle;
		map[a - j + SPACE][b + 1] = obstacle;
		map[a - j + SPACE][b - 1] = obstacle;
	}
	//�� �����̸� ���� ����
	if (a > 28) {
		a = 0;
		b = rand() % 15 + 2;
	}
}