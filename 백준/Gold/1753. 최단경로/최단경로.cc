#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
int v,e,k;
vector<pii> graph[20001];
int dist[20001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> v >> e >> k;
    for(int i = 0; i < e; i++)
    {
        int a,b,w; cin>>a>>b>>w;
        graph[a].push_back({b,w});
    }
}

void DIJKSTRA(int node)
{
    priority_queue<pii> pq;
    pq.push({0,node});//node까지의 거리,node
    dist[node] = 0;

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < cost) continue;

        for(int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            int nCost = cost + graph[now][i].second;
            if(nCost < dist[next])
            {
                dist[next] = nCost;
                pq.push({-nCost,next});
            }
        }
    }
}

void SOLVE()
{
    for(int i = 1; i <= v; i++) dist[i] = 2e9;
    DIJKSTRA(k);
    for(int i = 1; i <= v; i++)
    {
        if(dist[i] == 2e9) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}