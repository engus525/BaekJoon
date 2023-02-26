#include<iostream>
using namespace std;

int h, w;
int block[501][501];

int ans = 0;

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> h >> w;
	for (int i = 1; i <= w; i++)
	{
		int n; cin >> n;
		for (int j = 0; j < n; j++)
			block[h - j][i] = 1;
	}
}

bool isBlocked(int r, int c)
{
	bool left = false, right = false;
	// 양 끝자리면 빗물이 고일 수 없음
	if (c == 1 || c == w) return false;

	// 왼쪽
	for (int i = c - 1; i >= 1; i--)
		if (block[r][i] == 1)
		{
			left = true;
			break;
		}

	// 오른쪽
	for (int i = c + 1; i <= w; i++)
		if (block[r][i] == 1)
		{
			right = true;
			break;
		}

	return (left && right);
}

void solve()
{
	// 좌측 하단부터 우측으로 올라가며 탐색
	for(int i = h; i > 0; i--)
		for (int j = 1; j <= w; j++)
			if (block[i][j] == 0 && isBlocked(i, j))
				ans++;

	cout << ans;
}

int main()
{
	INPUT();
	solve();
}