#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int map[1001][1001];
int dp[1001][1001];

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> map[i][j];
}

void SOLVE()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];

	cout << dp[n][m];
}

int main()
{
	INPUT();
	SOLVE();
}