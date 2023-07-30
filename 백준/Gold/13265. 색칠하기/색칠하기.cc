#include <iostream>
#include <vector>
#include <queue>
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
typedef pair<long long, long long> pll;

int t, n, m;
vector<vector<int>> graph;
int visited[1001];

void INPUT()
{
    IAMFAST
    cin >> t;
}

bool BFS(int start)
{
    queue<pii> q;
    q.emplace(start, 1);
    visited[start] = 1;

    while (!q.empty())
    {
        auto [now, color] = q.front();
        q.pop();

        for (auto &next: graph[now])
        {
            if (visited[next] == color) return false;
            if (visited[next]) continue;

            visited[next] = (color == 1) ? 2 : 1;
            q.emplace(next, visited[next]);
        }
    }
    return true;
}

void solution()
{
    while (t--)
    {
        cin >> n >> m;
        for (auto &g: graph) g.clear();
        graph.resize(n + 1);
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < m; i++)
        {
            int s, e;
            cin >> s >> e;
            graph[s].emplace_back(e);
            graph[e].emplace_back(s);
        }

        bool possible = true;
        for (int i = 1; i <= n; i++)
            if (!visited[i])
                if (!BFS(i))
                {
                    possible = false;
                    break;
                }

        if (possible) cout << "possible\n";
        else cout << "impossible\n";
    }
}

int main()
{
    INPUT();
    solution();
}