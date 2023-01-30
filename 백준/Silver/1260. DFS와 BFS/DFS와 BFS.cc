#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <numeric>
#include <stack>
using namespace std;
/* –2,147,483,648 ~ 2,147,483,647 */

int n, m, v;
int graph[1001][1001];
bool visited[1001];
queue<int> q;

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		graph[x][y] = 1; graph[y][x] = 1;
	}
}

void DFS(int node)
{
	visited[node] = true;
	cout << node << " ";

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i] && graph[node][i] == 1)
			DFS(i);
	}
}

void BFS(int node)
{

	q.push(node);

	while (!q.empty())
	{
		cout << q.front() << " ";
		visited[q.front()] = false;

		for (int i = 1; i <= n; i++)
		{
			if (visited[i] && graph[q.front()][i] == 1)
			{
				q.push(i); visited[i] = false;
			}

		}
		q.pop();
	}
}

void solve()
{
	DFS(v);
	cout << '\n';
	BFS(v);
	
}

int main()
{

	//system("mode con cols=60 lines=40 | title 아~너무쉽다");
	INPUT();

	solve();
}