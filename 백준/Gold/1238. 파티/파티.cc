#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
int n,m,x;
vector<pii> graph[1001];
int dist[1001];
int backDist[1001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++)
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
    int ans = 0;

    // x에서 돌아오는 시간 구하기
    fill(dist,dist+n+1,2e9);
    DIJKSTRA(x);
    for(int i = 1; i <= n; i++) backDist[i] = dist[i];

    // x로 가는 시간 구하기
    for(int i = 1; i <= n; i++)
    {
        fill(dist,dist+n+1,2e9);
        DIJKSTRA(i);
        ans = max(ans,dist[x] + backDist[i]);
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}