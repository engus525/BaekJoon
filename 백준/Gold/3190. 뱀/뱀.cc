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

int n, k, l;
int board[101][101] = { 0, };
vector<pair<int, string>> turn; // 방향 변환 정보
vector<pair<int, int>> snake; // 뱀 위치 좌표들, 즉 현재위치는 snake의 마지막 index
int d = 1; // 북 0 동 1 남 2 서 3
bool finish = false;

int ans = 0;

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y; cin >> x >> y;
		board[x][y] = 1; // 사과 위치에 1
	}
	cin >> l;
	int sum = 0; // 8D 10D 를 8D 2D로 바꾸기 위한 초 누적합
	for (int i = 0; i < l; i++)
	{
		int x; string c;
		cin >> x >> c;
		turn.push_back(make_pair(x - sum, c));
		sum = x;
	}
	snake.push_back(make_pair(1, 1));
}

void changeD(string c)
{
	if (c == "L")
		d--;
	else d++;

	if (d == 4) d = 0;
	else if (d == -1) d = 3;
}

void MOVE()
{
	ans++;
	int X[4] = { -1,0,1,0 }, Y[4] = { 0,1,0,-1 };
	int nx = snake[snake.size() - 1].first + X[d];
	int ny = snake[snake.size() - 1].second + Y[d];

	// 벽
	if (nx == 0 || nx == n + 1 || ny == 0 || ny == n + 1)
	{
		finish = true; return;
	}

	// 몸에 부딪힘
	for (int i = 0; i < snake.size(); i++)
	{
		if (snake[i].first == nx && snake[i].second == ny)
		{
			finish = true; return;
		}
	}

	// 이동 가능
	snake.push_back(make_pair(nx, ny));
	//사과 없으면
	if (board[nx][ny] == 0)
		snake.erase(snake.begin());
	else
		board[nx][ny] = 0;

}

void solve()
{
	for (int i = 0; i < turn.size(); i++)
	{
		for (int j = 0; j < turn[i].first; j++)
		{
			MOVE();
			if (finish == true)
			{
				cout << ans; return;
			}
		}
		changeD(turn[i].second);
	}

	//모든 이동 후에도 게임이 끝나지 않은 경우
	while (finish == false)
		MOVE();

	cout << ans;
}

int main()
{
	INPUT();

	solve();
}