#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stdio.h>
using namespace std;
/* 	–2,147,483,648 ~ 2,147,483,647 */

int board[20][20];

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j < 20; j++)
			cin >> board[i][j];
}

bool victory(int x, int y, int who)
{
	int cnt = 1;
	// 가로 승
	for (int i = 1; i < 5; i++)
	{
		//6목
		if (board[x][y - 1] == who)
			break;

		if (board[x][y + i] == who)
			cnt++;
		else break;

		if (cnt == 5 && board[x][y + i + 1] != who)
			return true;
	}
	// 우하향 승
	cnt = 1;
	for (int i = 1; i < 5; i++)
	{
		//6목
		if (board[x - 1][y - 1] == who)
			break;

		if (board[x + i][y + i] == who)
			cnt++;
		else break;

		if (cnt == 5 && board[x + i + 1][y + i + 1] != who)
			return true;
	}
	// 세로 승
	cnt = 1;
	for (int i = 1; i < 5; i++)
	{
		//6목
		if (board[x - 1][y] == who)
			break;

		if (board[x + i][y] == who)
			cnt++;
		else break;

		if (cnt == 5 && board[x + i + 1][y] != who)
			return true;
	}
	// 우상향 승
	cnt = 1;
	for (int i = 1; i < 5; i++)
	{
		//6목
		if (board[x + 1][y  - 1] == who)
			break;

		if (board[x - i][y + i] == who)
			cnt++;
		else break;

		if (cnt == 5 && board[x - i - 1][y + i + 1] != who)
			return true;
	}
	return false;
}

void solve()
{
	//위에서 아래로 탐색 -> 첫번째 돌이 가장 왼쪽 바둑알
	for (int i = 1; i < 20; i++)//열
		for (int j = 1; j < 20; j++)//행
		{
			if (board[j][i] == 1 || board[j][i] == 2)
				if (victory(j, i, board[j][i]))
				{
					cout << board[j][i] << '\n' << j << " " << i;
					return;
				}

		}

	// 승자 없을때
	cout << 0;
}

int main()
{
	INPUT();

	solve();
}