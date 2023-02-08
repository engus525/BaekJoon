#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int v;
int a,b,d;
typedef pair<int,int> pii;
vector<pii> graph[10001];

bool visited[10001];

void INPUT()
{
	IAMFAST
	cin >> v;
	for(int i = 0; i < v-1; i++)
	{
		cin >> a >> b >> d;
		graph[a].push_back({b,d});
		graph[b].push_back({a,d});
	}
}

pii DFS(int x)
{
	int node = x;
	int maxDist = 0;

	visited[x] = true;
	for(int i = 0; i < graph[x].size(); i++)
	{
		int nx = graph[x][i].first;
		int dist = graph[x][i].second;
		if(visited[nx]) continue;

		pii temp = DFS(nx);
		temp.second += dist;
		if(maxDist < temp.second)
		{
			node = temp.first;
			maxDist = temp.second;
		}
	}
	visited[x] = false;

	return {node,maxDist};
}

void SOLVE()
{
	int first = DFS(1).first;
	int second = DFS(first).second;

	cout << second;
}

int main()
{
	INPUT();
	SOLVE();
}