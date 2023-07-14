#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m, r;
vector<int> graph[100001];
int visited[100001];
int cnt = 1;

void INPUT()
{
    IAMFAST
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        int u,v; cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
}

void BFS()
{
    queue<int> q;
    q.emplace(r);
    visited[r] = cnt++;

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();

        for (auto &next : graph[now])
        {
            if (visited[next]) continue;

            visited[next] = cnt++;
            q.emplace(next);
        }
    }
}

void solution()
{
    for(auto &g : graph) sort(g.begin(),g.end(),greater());
    BFS();
    for(int i = 1; i <= n; i++) cout << visited[i] << '\n';
}

int main()
{
    INPUT();
    solution();
}