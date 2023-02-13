#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,e;
typedef long long ll;
typedef pair<int,ll> pii;
vector<pii> graph[801];
int v1,v2;

ll dist[1001];

void INPUT()
{
	IAMFAST
	cin >> n >> e;
	for(int i = 0; i < e; i++)
	{
		int a,b,c; cin >> a >> b >> c;
		graph[a].emplace_back(b,c);
		graph[b].emplace_back(a,c);
	}
	cin >> v1 >> v2;
}

void ijk(int start)
{
	fill(dist+1,dist+n+1,2e9);
	priority_queue<pair<ll,int>> pq;
	pq.push({0,start});
	dist[start] = 0;

	while(!pq.empty())
	{
		int now = pq.top().second;
		ll d1 = -pq.top().first;
		pq.pop();

		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			ll d2 = graph[now][i].second + d1;
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
	ijk(1);
	ll _v1 = dist[v1];
	ll _v2 = dist[v2];

	ijk(v1);
	ll v1_v2 = dist[v2];
	ll v1_n = dist[n];

	ijk(v2);
	ll v2_n = dist[n];

	ll ans = min(_v1+v1_v2+v2_n , _v2+v1_v2+v1_n);
	if(ans >= 2e9) cout << -1;
	else cout << ans;
}

int main()
{
	INPUT();
	SOLVE();
}