#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m, start, fin, money;
vector<vector<pii>> graph;
int dist[11];
bool visited[11];
struct INFO
{
    int d;
    int now;
    int maxM;
};

struct comp
{
    bool operator()(INFO a, INFO b)
    {
        return a.d > b.d;
    }
};


void INPUT()
{
    IAMFAST
    cin >> n >> m >> start >> fin >> money;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int s, e, d;
        cin >> s >> e >> d;
        graph[s].emplace_back(e, d);
        graph[e].emplace_back(s, d);
    }
}

int ijk()
{
    int ans = 2e9;

    priority_queue<INFO, vector<INFO>, comp> pq;
    pq.push({0, start, 0});
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [d1, now, maxM] = pq.top();
        pq.pop();

        if (now == fin) ans = min(ans, maxM);

        for (int i = 0; i < graph[now].size(); i++)
        {
            auto [next, d2] = graph[now][i];
            int nd = d1 + d2;

            if (dist[next] < nd) continue;
            if (nd > money) continue;

            maxM = max(maxM, d2);
            dist[next] = nd;
            pq.push({nd, next, maxM});
        }
    }

    return ans;
}

void solution()
{
    for (int i = 1; i <= n; i++) dist[i] = 2e9;

    int ans = ijk();
    (ans == 2e9) ? cout << -1 : cout << ans;
}

int main()
{
    INPUT();
    solution();
}