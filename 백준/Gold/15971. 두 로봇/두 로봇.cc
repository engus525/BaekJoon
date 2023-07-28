#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int n, s, e;
vector<vector<pii>> graph;
vector<int> route;
int dist[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> s >> e;
    graph.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
}

void ijk()
{
    priority_queue<pair<pii, vector<int>>> pq;
    pq.push({{0, s},
             {s}});
    dist[s] = 0;

    while (!pq.empty())
    {
        auto [d1, now] = pq.top().first;
        auto v = pq.top().second;
        d1 = -d1;
        pq.pop();

        if (now == e) route = v;

        for (auto &g: graph[now])
        {
            auto [next, d2] = g;
            if (dist[next] < d1 + d2) continue;

            dist[next] = d1 + d2;
            v.emplace_back(next);
            pq.push({{-(d1 + d2), next}, v});
            v.pop_back();
        }
    }
}

void solution()
{
    fill(dist, dist + n + 1, 2e9);
    ijk();
    int ans = (s == e) ? 0 : 2e9;
    for (int i = 0; i < route.size() - 1; i++)
        ans = min(ans,
                  dist[route[i]] + (dist[e] - dist[route[i + 1]]));
    cout << ans;

}

int main()
{
    INPUT();
    solution();
}