#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, m;
char sex[1001];
struct KS
{
    int s,e,v;
};
vector<KS> graph;
int parent[1001];
bool visited[1001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> sex[i];
    for(int i = 0; i < m; i++)
    {
        int s,e,v; cin >> s >> e >> v;
        if(sex[s] != sex[e]) graph.push_back({s,e,v});
    }
}

int Find(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if(x == y) return false;

    visited[x] = true;
    visited[y] = true;
    if(x > y) parent[x] = y;
    else parent[y] = x;
    return true;
}


void SOLVE()
{
    for(int i = 1; i <= n; i++) parent[i] = i;
    sort(graph.begin(), graph.end(),[](KS a,KS b){return a.v < b.v;});

    int ans = 0;
    for(auto &i : graph)
        if(Union(i.s,i.e))
            ans += i.v;

    bool allVisited = true;
    for(int i = 1; i <= n; i++)
        if(!visited[i]) allVisited = false;
    if(allVisited) cout << ans;
    else cout << -1;
}

int main()
{
    INPUT();
    SOLVE();
}