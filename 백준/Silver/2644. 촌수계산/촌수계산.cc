#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, x, y, m;
vector<int> graph[101];
int visited[101];

void INPUT()
{
	IAMFAST
	cin >> n >> x >> y >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void BFS()
{
	queue<int> q;
	q.push(x);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];
			if(visited[next]) continue;

			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}
}

void SOLVE()
{
	BFS();

	if (visited[y]) cout << visited[y];
	else cout << -1;
}

int main()
{
	INPUT();
	SOLVE();
}