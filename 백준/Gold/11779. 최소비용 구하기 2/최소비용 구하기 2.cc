#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
typedef pair<int,int> pii;
vector<pii> graph[1001];
int s,e;

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
	cin >> s >> e;
}

vector<int> ijk()
{
	fill(dist+1,dist+n+1,1e9);
	priority_queue<pair<pii,vector<int>>> pq;
	pq.push({{0,s},{s}});
	dist[s] = 0;

	while(!pq.empty())
	{
		int now = pq.top().first.second;
		int d1 = -pq.top().first.first;
		vector<int> v = pq.top().second;
		pq.pop();

		if(now == e) return v;

		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int d2 = graph[now][i].second + d1;
			v.emplace_back(next);

			if(dist[next] > d2)
			{
				dist[next] = d2;
				pq.push({{ -d2, next },v});
			}
			v.pop_back();
		}
	}

}

void SOLVE()
{
	vector<int> ans = ijk();
	cout << dist[e] << '\n' << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}

int main()
{
	INPUT();
	SOLVE();
}