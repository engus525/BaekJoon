#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

int n, m;
struct KS
{
    int s, e, v;
    bool exist;
};
vector<KS> graph;
int parent[10001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c; bool d;
        cin >> a >> b >> c >> d;
        graph.push_back({a, b, c, d});
    }
}

int Find(int x)
{
    if (x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y) return true;

    if (x > y) parent[x] = y;
    else parent[y] = x;
    return false;
}

void solution()
{
    for(int i = 1; i <= n; i++) parent[i] = i;
    sort(graph.begin(),graph.end(),[](KS &a, KS &b)
    {
        return a.v > b.v;
    });

    for(auto &g : graph)
        if (g.exist) Union(g.s, g.e);

    ll ans = 0;
    for(auto &g : graph)
    {
        if (Union(g.s, g.e))
        {
            if (!g.exist) ans += g.v;
            continue;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}