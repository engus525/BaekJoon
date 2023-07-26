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

int n,m;
vector<vector<pii>> graph;
int dist[5001];
int s,e;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    graph.resize(n+1);
    for(int i = 0; i < m; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,c);
    }
    cin >> s >> e;
}

int ijk()
{
    priority_queue<pii> pq;
    pq.emplace(0,s);
    dist[s] = 0;

    while(!pq.empty())
    {
        auto [d1, now] = pq.top();
        d1 = -d1;
        pq.pop();

        if (now == e) return dist[now];

        for (auto &g : graph[now])
        {
            auto [next, d2] = g;

            if (dist[next] < d1 + d2) continue;
            dist[next] = d1 + d2;
            pq.emplace(-(d1+d2), next);
        }
    }
}

void solution()
{
    fill(dist, dist + n + 1, 2e9);
    cout << ijk();
}

int main()
{
    INPUT();
    solution();
}