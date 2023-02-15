#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int dist[201][201];

int ans[201][201];

void INPUT()
{
	IAMFAST
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dist[i][j] = 1e9;

	for(int i = 0; i < m; i++)
	{
		int a,b,c; cin >> a >> b >> c;
		dist[a][b] = dist[b][a] = c;
		ans[a][b] = b;
		ans[b][a] = a;
	}
}


void ijk()
{
	for(int i = 1; i <= n; i++) dist[i][i] = 0 , ans[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					ans[i][j] = ans[i][k];
				}
}

void SOLVE()
{

	ijk();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(i==j) cout << "- ";
			else cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
}

int main()
{
	INPUT();
	SOLVE();
}