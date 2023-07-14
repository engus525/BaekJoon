#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m;
vector<int> graph[20001];
int visited[20001];
int ans[3];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
}

void BFS()
{
    queue<int> q;
    q.emplace(1);
    visited[1] = 0;

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();

        for (auto &next: graph[now])
        {
            if (visited[next] != -1) continue;

            visited[next] = visited[now] + 1;
            q.emplace(next);
        }
    }
}

void solution()
{
    memset(visited,-1,sizeof visited);
    BFS();
    for(int i = 1; i <= n; i++)
    {
        if (visited[i] >= ans[1])
        {
            if(visited[i] == ans[1]) ans[2]++;
            else ans[0] = i, ans[1] = visited[i], ans[2] = 1;
        }
    }

    for(int &a : ans) cout << a << " ";
}

int main()
{
    INPUT();
    solution();
}