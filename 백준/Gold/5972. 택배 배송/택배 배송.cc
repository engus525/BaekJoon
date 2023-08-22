#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
vector<vector<pii>> graph;
int dist[50001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    graph.resize(n+1);
    for (int i = 0 ; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,c);
    }
}

int dijkstra()
{
    priority_queue<pii> pq;
    pq.emplace(0, 1);

    while (!pq.empty())
    {
        auto [d1, now] = pq.top();
        d1 *= -1;
        pq.pop();

        if (now == n) return dist[now];

        for(auto [next, d2] : graph[now])
        {
            int nd = d1 + d2;
            if (dist[next] <= nd) continue;

            dist[next] = nd;
            pq.emplace(-nd, next);
        }
    }
}

void solution()
{
    for(int i = 1; i <= n; i++) dist[i] = 2e9;
    cout << dijkstra();
}

int main()
{
    INPUT();
    solution();
}