#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m,r;
int item[101];
typedef pair<int,int> pii;
vector<pii> graph[101];

int dist[101];

void INPUT()
{
	IAMFAST
	cin >> n >> m >> r;
	for(int i = 1; i <= n; i++) cin >> item[i];
	for(int i = 0; i < r; i++)
	{
		int a,b,l; cin >> a >> b >> l;
		graph[a].emplace_back(b,l);
		graph[b].emplace_back(a,l);
	}
}

int setAns()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(dist[i] <= m)
			cnt += item[i];
	return cnt;
}

void ijk(int start)
{
	fill(dist+1,dist+1+n,2e9);

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

			if(dist[next] > d1 + d2)
			{
				dist[next] = d1 + d2;
				pq.push({-dist[next],next});
			}
		}
	}
}

void SOLVE()
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ijk(i);
		ans = max(ans,setAns());
	}
	cout << ans;

}

int main()
{
	INPUT();
	SOLVE();
}