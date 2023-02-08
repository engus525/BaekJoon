#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int v;
int s,a,b;
typedef pair<int,int> pii;
vector<pii> graph[100001];

bool visited[100001];
int ans = -1;

void INPUT()
{
	IAMFAST
	cin >> v;
	for(int i = 1; i <= v; i++)
	{
		cin >> s;
		while(true)
		{
			cin >> a; if(a==-1) break;
			cin >> b;
			graph[s].push_back({a,b});
		}
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