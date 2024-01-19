#include <iostream>
using namespace std;

int n, m, b;
int map[501][501];

int ansTime = 2e9 , ansHeight = 0;

void INPUT()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

int cultivate(int targetHeight)
{
	int time = 0; // 소요 시간
	int tb = b; // 인벤토리

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (map[x][y] > targetHeight)
			{ // 블록 제거 후 인벤토리 (2초)
				time += 2 * (map[x][y] - targetHeight);
				tb += map[x][y] - targetHeight;
			}
			else if (map[x][y] < targetHeight)
			{ // 인벤토리에서 블록 꺼내 놓기 (1초)
				time += targetHeight - map[x][y];
				tb -= targetHeight - map[x][y];
			}
		}
	}
	if (tb < 0) return -1; // 인벤토리 블록 부족
	else return time;
}

void SOLVE()
{
	for (int i = 0; i < 257; i++)
	{
		int tempAns = cultivate(i);

		if (tempAns == -1) continue; // 인벤토리 블록 부족
		else if (tempAns <= ansTime)
		{
			ansTime = tempAns; // 소요시간
			ansHeight = i; // 땅의 높이
		}

	}
	cout << ansTime << " " << ansHeight;

}

int main()
{
	INPUT();
	SOLVE();
}
