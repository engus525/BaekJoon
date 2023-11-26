#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
vector<vector<int>> graph;
int dist[101][101];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
}

void BFS(int start)
{
    queue<int> q;
    q.emplace(start);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (auto &next : graph[now])
        {
            if (start == next) continue;
            if (dist[start][next]) continue;

            dist[start][next] = dist[start][now] + 1;
            q.emplace(next);
        }
    }
}

void solution()
{
    for (int i = 1; i <= n; i++) BFS(i);

    int minDist = 2e9;
    int ans;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= n; j++) temp += dist[i][j];
        if (minDist > temp)
            ans = i, minDist = temp;
    }
    cout << ans;

}

int main()
{
    INPUT();
    solution();
}