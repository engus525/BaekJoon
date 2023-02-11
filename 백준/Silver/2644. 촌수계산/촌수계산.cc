#include <iostream>
#include <queue>
using namespace std;

int n, x, y, m;
int map[101][101];
bool visited[101];
int depth[101];

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> x >> y >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
}

void BFS(int node)
{
	queue<int> q;
	q.push(node);

	visited[node] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i] && map[now][i] == 1)
			{
				visited[i] = true;
				depth[i] = depth[now] + 1;
				q.push(i);
			}
		}
	}
}

void SOLVE()
{
	BFS(x);

	if (depth[y] != 0) cout << depth[y];
	else cout << -1;
}

int main()
{
	INPUT();
	SOLVE();
}