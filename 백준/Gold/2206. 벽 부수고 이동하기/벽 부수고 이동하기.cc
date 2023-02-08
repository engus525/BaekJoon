#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <memory.h> // memset
#include <numeric>
#include <stack>
#include <sstream>
using namespace std;
/* –2,147,483,648 ~ 2,147,483,647 */

int n, m;
int map[1000][1000];
int visited[2][1000][1000]; // [0][][] : 벽 부숨, [1][][] : 벽 안 부숨

void INPUT()
{
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
}

int BFS(int x, int y)
{
	struct NODE
	{
		int x;
		int y;
		int bomb; // 0 : 벽 부숨, 1 : 벽 안 부숨
	};
	queue<NODE> q;
	q.push({ x, y, 1 });

	visited[1][x][y] = 1;

	while (!q.empty())
	{

		NODE now = q.front();
		q.pop();

		if (now.x == n - 1 && now.y == m - 1)
			return visited[now.bomb][now.x][now.y];

		for (int i = 0; i < 4; i++)
		{
			int dp[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; // 우 좌 하 상
			int nx = now.x + dp[i][0], ny = now.y + dp[i][1];

			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				/*
				1. 벽 안 부순 상태에서 벽 만났을 때 : visited 전환, q push
				2. 벽 부순 상태에서 벽 만났을 때 : continue


				3. 벽 안 부순 상태에서 길 만났을 때
				4. 벽 부순 상태에서 길 만났을 때

				3, 4번 모두 visited 전환없이 q에 push
				*/

				if (!visited[0][nx][ny] && now.bomb == 1 && map[nx][ny] == 1)
				{
					q.push({ nx,ny,0 });
					visited[0][nx][ny] = visited[1][now.x][now.y] + 1;
				}
				else if (!visited[now.bomb][nx][ny] && map[nx][ny] == 0)
				{
					q.push({ nx,ny,now.bomb });
					visited[now.bomb][nx][ny] = visited[now.bomb][now.x][now.y] + 1;
				}

			}
		}

	}
	return -1;
}

void SOLVE()
{
	cout << BFS(0, 0);

	/*for (int i = 0; i < n; i++)
	{
		cout << '\n';
		for (int j = 0; j < m; j++)
			cout << visited[0][i][j] << " ";
	}
		
	cout << "no crush\n";
	for (int i = 0; i < n; i++)
	{
		cout << '\n';
		for (int j = 0; j < m; j++)
			cout << visited[1][i][j] << " ";
	}*/


}

int main()
{
	INPUT();

	SOLVE();
}