#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stdio.h>
#include<ctime>
#include<numeric>
#include<stack>
using namespace std;
/* –2,147,483,648 ~ 2,147,483,647 */

int n, m, r, c, d;
int map[51][51];
int ans = 0;

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> r >> c >> d;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

int backX(int x, int d)
{
	int X[4] = { 1,0,-1,0 };
	return x + X[d];
}

int backY(int y, int d)
{
	int Y[4] = { 0,-1,0,1 };
	return y + Y[d];
}

void clean(int x, int y, int di)
{
	// 현재 위치를 청소한다
	map[x][y] = 2; ans++;

	int X[4] = { 0,-1,0,1 };
	int Y[4] = { -1,0,1,0 };
	int nd = di;
	int cantClean = 0;
	
	for (int i = 0; i < 4; i++)
	{
		// 탐색 방향 조정
		int idx = di - i;
		if (idx < 0) idx = 4 + idx;

		//탐색 좌표
		int nx = x + X[idx], ny = y + Y[idx];

		// 회전후 방향
		if (nd == 0) nd = 3;
		else nd--;

		// 범위 밖
		if (nx < 1 || ny < 1 || nx >= n || ny >= m)
		{
			//cout << "범위 밖!!:" << '\n';
			cantClean++;
			continue;
		}

		//청소 가능
		else if (map[nx][ny] == 0)
		{
			clean(nx, ny, nd);
			return;
		}
		else
			cantClean++;
	}
	
	//네 방향 모두 청소 or 벽
	if (cantClean == 4)
	{
		int bx = backX(x, di), by = backY(y, di);
		// 후진 가능
		if (map[bx][by] == 2)
		{
			ans--;
			clean(bx, by, di);
		}
		else if (map[bx][by] == 1)
			return;
	}
}

void solve()
{
	clean(r, c, d);
	cout << ans;
}

int main()
{
	INPUT();

	solve();
}