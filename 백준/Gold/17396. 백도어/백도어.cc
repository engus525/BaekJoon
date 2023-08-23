#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
vector<vector<pll>> graph;
ll dist[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    graph.resize(n+1);
    for (int i = 0; i < n; i++)
    {
        ll visible; cin >> visible;
        if (i == n - 1) continue;
        dist[i] = -visible;
    }
    for (int i = 0; i < m; i++)
    {
        ll a, b, c; cin >> a >> b >> c;
        if (dist[a] == -1 || dist[b] == -1) continue;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,c);
    }
}

ll dijkstra()
{
    priority_queue<pll> pq;
    pq.emplace(0, 0);

    while (!pq.empty())
    {
        auto [d1, now] = pq.top();
        d1 *= -1;
        pq.pop();

        if (dist[now] < d1) continue;
        if (now == n - 1) return dist[now];

        for(auto [next, d2] : graph[now])
        {
            ll nd = d1 + d2;
            if (dist[next] <= nd) continue;

            dist[next] = nd;
            pq.emplace(-nd, next);
        }
    }
    return -1;
}

void solution()
{
    for(int i = 0; i < n; i++)
        if (dist[i] != -1) dist[i] = 1e18;
    cout << dijkstra();
}

int main()
{
    INPUT();
    solution();
}