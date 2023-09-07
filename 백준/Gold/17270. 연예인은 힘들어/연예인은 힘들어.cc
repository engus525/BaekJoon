#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int a, b, c;
int s1, s2;
int dist1[101], dist2[101];
vector<vector<pii>> graph;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    cin >> s1 >> s2;
}

void dijkstra()
{
    priority_queue<pii> pq1, pq2;
    pq1.emplace(0, s1), pq2.emplace(0, s2);
    dist1[s1] = 0, dist2[s2] = 0;

    while (!pq1.empty())
    {
        auto [d1, now] = pq1.top();
        d1 *= -1;
        pq1.pop();

        for (auto [next, d2] : graph[now])
        {
            int nd = d1 + d2;
            if (dist1[next] < nd) continue;

            dist1[next] = nd;
            pq1.emplace(-nd, next);
        }
    }

    while (!pq2.empty())
    {
        auto [d1, now] = pq2.top();
        d1 *= -1;
        pq2.pop();

        for (auto [next, d2] : graph[now])
        {
            int nd = d1 + d2;
            if (dist2[next] < nd) continue;

            dist2[next] = nd;
            pq2.emplace(-nd, next);
        }
    }
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        dist1[i] = 1e9;
        dist2[i] = 1e9;
    }
    dijkstra();

    int minDist = 1e9;
    for (int i = 1; i <= n; i++)
    {
        //cout << i << " : " << dist1[i] << " " << dist2[i] << '\n';
        if (i == s1 || i == s2) continue;
        if (minDist > dist1[i] + dist2[i])
        {
            minDist = dist1[i] + dist2[i];
        }
    }

    int ans = -1;
    int s1MinDist = 1e9;
    for (int i = 1; i <= n; i++)
    {
        if (i == s1 || i == s2) continue;

        int dist = dist1[i] + dist2[i];
        if (dist > minDist) continue;
        if (dist1[i] > dist2[i]) continue;

        //cout << i << " : " << dist1[i] << " " << dist2[i] << '\n';
        if (minDist == dist)
        {
            if (s1MinDist > dist1[i])
                s1MinDist = dist1[i],
                ans = i;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}
