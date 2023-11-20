#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m, start, fin, money;
vector<vector<pii>> graph;
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
    visited[start] = true;

    while (!pq.empty())
    {
        auto [d1, now, maxM] = pq.top();
        pq.pop();
        visited[now] = true;

        if (now == fin) ans = min(ans, maxM);

        for (int i = 0; i < graph[now].size(); i++)
        {
            auto [next, d2] = graph[now][i];
            int nd = d1 + d2;

            if (nd > money) continue;
            if (visited[next]) continue;

//            cout << "이 경로의 maxM = " << maxM << '\n';
//            cout << now << " to " << next << " at " << d2 << ", and total " << nd << '\n';
            int routeMax = max(maxM, d2);
            pq.push({nd, next, routeMax});
        }
    }

    return ans;
}

void solution()
{
    int ans = ijk();
    (ans == 2e9) ? cout << -1 : cout << ans;
}

int main()
{
    INPUT();
    solution();
}