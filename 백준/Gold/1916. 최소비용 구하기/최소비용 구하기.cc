#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
typedef pair<int,int> pii;
vector<pii> graph[1001];
int start,goal;

int dist[1001];

void INPUT()
{
	IAMFAST
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a,b,c; cin >> a >> b >> c;
		graph[a].emplace_back(b,c);
	}
	cin >> start >> goal;
}

void ijk()
{
	priority_queue<pii> pq;
	pq.push({0,start});
	dist[start] = 0;

	while(!pq.empty())
	{
		int now = pq.top().second;
		int d1 = -pq.top().first;
		pq.pop();
		
		if(now == goal) return;

		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int d2 = graph[now][i].second + d1;
			if(dist[next] > d2)
			{
				dist[next] = d2;
				pq.push({-d2,next});
			}
		}
	}
}

void SOLVE()
{
	fill(dist+1,dist+n+1,2e9);
	ijk();
	cout << dist[goal];
}

int main()
{
	INPUT();
	SOLVE();
}