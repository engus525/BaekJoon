#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<vector<int>> graph;
set<int> ans;
bool visited[101];

void INPUT()
{
    IAMFAST
    cin >> n;
    graph.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int to;
        cin >> to;
        graph[i].emplace_back(to);
    }
}

void DFS(int now, int start, vector<int> route)
{
    if (visited[now])
    {
        if (now == start)
        {
            for (auto &r : route)
                ans.insert(r);
        }
        return;
    }

    visited[now] = true;
    int next = graph[now][0];

    route.emplace_back(next);
    DFS(next, start, route);
    route.pop_back();
    visited[next] = false;
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        DFS(i, i, {});
    }

    for (int i = 1; i <= n; i++)
        if (graph[i][0] == i)
            ans.insert(i);

    cout << ans.size() << '\n';
    for (auto &a : ans) cout << a << '\n';
}

int main()
{
    INPUT();
    solution();
}