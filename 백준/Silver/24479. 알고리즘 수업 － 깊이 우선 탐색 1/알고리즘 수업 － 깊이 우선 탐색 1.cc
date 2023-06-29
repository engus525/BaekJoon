#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m, r;
vector<int> graph[100001];
int visited[100001];
int order = 1;

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

void DFS(int x)
{
    visited[x] = order++;

    for (auto &g: graph[x])
    {
        if (visited[g]) continue;
        DFS(g);
    }

}

void SOLVE()
{
    for(int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    DFS(r);

    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) cout << visited[i] << '\n';
        else cout << 0 << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}