#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int t, n, u, v;
vector<vector<int>> graph;
int MAX = ceil(log2(10001)) + 1;
bool haveParent[10001];
int parent[10001][20];
int depth[10001];

void INPUT()
{
    IAMFAST
    cin >> t;
}

void init()
{
    for (auto &g: graph) g.clear();
    memset(parent, -1, sizeof parent);
    memset(depth, -1, sizeof depth);
    memset(haveParent, false, sizeof haveParent);
}

int findRoot()
{
    for (int i = 1; i <= n; i++)
        if (!haveParent[i]) return i;
}

void DFS(int now)
{
    for (auto &next: graph[now])
    {
        if (depth[next] != -1) continue;
        depth[next] = depth[now] + 1;
        parent[next][0] = now;
        DFS(next);
    }
}

void setParent()
{
    for (int i = 1; i < MAX; i++)
        for (int j = 1; j <= n; j++)
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
}

int LCA(int x, int y)
{
    if (depth[x] < depth[y]) swap(x,y);

    int gap = depth[x] - depth[y];
    for(int i = 0; gap; i++)
    {
        if (gap % 2) x = parent[x][i];
        gap /= 2;
    }

    if(x != y)
    {
        for(int i = MAX; i >= 0; i--)
        {
            if(parent[x][i] == -1) continue;
            if(parent[x][i] == parent[y][i]) continue;

            x = parent[x][i];
            y = parent[y][i];
        }
        x = parent[x][0];
    }
    return x;
}

void solution()
{
    while (t--)
    {
        init();
        //input
        cin >> n;
        graph.resize(n+1);
        for (int i = 0; i < n - 1; i++)
        {
            int s, e;
            cin >> s >> e;
            graph[s].emplace_back(e);
            haveParent[e] = true;
        }
        cin >> u >> v;

        DFS(findRoot());
        setParent();
        cout << LCA(u,v) << "\n";
    }
}

int main()
{
    INPUT();
    solution();
}