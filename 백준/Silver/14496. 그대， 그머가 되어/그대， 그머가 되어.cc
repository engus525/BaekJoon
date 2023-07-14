#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int a, b, n, m;
vector<int> graph[1001];
int visited[1001];

void INPUT()
{
    IAMFAST
    cin >> a >> b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
}

int BFS()
{
    queue<int> q;
    q.emplace(a);
    visited[a] = 0;

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();

        if(now == b) return visited[now];

        for (auto &next: graph[now])
        {
            if (visited[next] != -1) continue;

            visited[next] = visited[now] + 1;
            q.emplace(next);
        }
    }
    return -1;
}

void solution()
{
    memset(visited,-1,sizeof visited);
    cout << BFS();
}

int main()
{
    INPUT();
    solution();
}