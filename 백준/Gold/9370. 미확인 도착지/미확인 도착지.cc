#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int tc,n,m,t;
int s,g,h;
typedef pair<int,int> pii;
vector<pii> graph[2001];
int candi[101];//목적지 후보

int origin[2001];//최단 경로
int dist[2001];//g h를 반드시 지나는 최단 경로


void INPUT()
{
	IAMFAST
	cin >> tc;
}

void Init()
{
	for(int i = 1; i <= 2000; i++) graph[i].clear();
}

int Disconnect()
{
	int rtn;
	for(int i = 0; i < graph[g].size(); i++)
		if(graph[g][i].first == h)
			rtn = graph[g][i].second,
			graph[g][i].second = -1;
	for(int i = 0; i < graph[h].size(); i++)
		if(graph[h][i].first == g)
			graph[h][i].second = -1;
	return rtn;
}

void ijk(int start)
{
	fill(dist+1,dist+n+1,2e9);
	priority_queue<pii> pq;
	pq.push({0,start});
	dist[start] = 0;

	while(!pq.empty())
	{
		int now = pq.top().second;
		int d1 = -pq.top().first;
		pq.pop();

		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int d2 = graph[now][i].second;
			if(d2 == -1) continue;

			if(dist[next] > d1 + d2)
			{
				dist[next] = d1+d2;
				pq.push({ -(d1+d2), next });
			}
		}
	}

}

void SOLVE()
{
	while(tc--)
	{
		Init();

		//Input
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for(int i = 0; i < m; i++)
		{
			int a,b,d; cin >> a >> b >> d;
			graph[a].emplace_back(b,d);
			graph[b].emplace_back(a,d);
		}
		for(int i = 0; i < t; i++) cin >> candi[i];

		//Solve
		ijk(s);
		int toG = dist[g];
		int toH = dist[h];
		for(int i = 1; i <= n; i++) origin[i] = dist[i];

		//g-h 경로 차단
		int connect = Disconnect();

		set<int> ans;
		ijk(g);
		for(int i = 0; i < t; i++)
			if(dist[candi[i]] != 2e9)
				if(origin[candi[i]] == toH + connect + dist[candi[i]])
					ans.insert(candi[i]);
		ijk(h);
		for(int i = 0; i < t; i++)
			if(dist[candi[i]] != 2e9)
				if(origin[candi[i]] == toG + connect + dist[candi[i]])
					ans.insert(candi[i]);

		//Output
		set<int>::iterator it;
		for(it = ans.begin(); it != ans.end(); it++)
			cout << *it << " ";
		cout << '\n';
	}

}

int main()
{
	INPUT();
	SOLVE();
}