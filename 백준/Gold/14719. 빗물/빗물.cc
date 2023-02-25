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
	if (c == 1 || c == w)
		return false;

	for (int i = c - 1; i >= 1; i--)
		if (block[r][i] == 1)
		{
			left = true;
			break;
		}

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
	for(int i = h; i > 0; i--)
		for (int j = 1; j <= w; j++)
			if (block[i][j] == 0 && isBlocked(i, j))
				ans++;

	cout << ans;

	/*for (int i = 1; i <= h; i++)
	{
		cout << '\n';
		for (int j = 1; j <= w; j++)
		{
			cout << block[i][j] << " ";
		}
	}*/

}

int main()
{
	INPUT();

	solve();
}