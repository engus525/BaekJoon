#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
char map[51][51];
struct KS
{
    int u, v, w;
};
vector<KS> graph;
int parent[51];
bool visited[51];
int ans = 0;

void INPUT()
{
    //IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            scanf("%1s", &map[i][j]);
            if(map[i][j] == '0') continue;

            if('a' <= map[i][j] && map[i][j] <= 'z')
                graph.push_back({i,j,map[i][j]-'a'+1}),
                ans += map[i][j]-'a'+1;
            else if('A' <= map[i][j] && map[i][j] <= 'Z')
                graph.push_back({i,j,map[i][j]-'A'+27}),
                ans += map[i][j]-'A'+27;

        }
}

int Find(int x)
{
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y) return false;

    if (x > y) parent[x] = y;
    else parent[y] = x;
    visited[x] = visited[y] = true;
    return true;
}

void SOLVE()
{
    for (int i = 1; i <= n; i++) parent[i] = i;
    sort(graph.begin(), graph.end(), [](KS a, KS b)
    { return a.w < b.w; });

    for (auto &g: graph)
        if (Union(g.u, g.v))
            ans -= g.w;

    bool all = true;
    for(int i = 1; i <= n; i++)
    {
        parent[i] = Find(i);
        if(!visited[i]) all = false;
    }

    bool allLinked = true;
    for(int i = 1; i < n; i++)
        if(parent[i] != parent[i+1])
            allLinked = false;

    if((allLinked && all) || n == 1) cout << ans;
    else cout << -1;
}

int main()
{
    INPUT();
    SOLVE();
}