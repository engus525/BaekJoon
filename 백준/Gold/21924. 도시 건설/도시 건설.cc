#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
typedef long long ll;
struct KS
{
    int s,e;
    ll v;
};
vector<int> map[100001];
vector<KS> graph;
int parent[100001];
bool visited[100001];
ll total = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        KS ks; cin >> ks.s >> ks.e >> ks.v;
        map[ks.s].emplace_back(ks.e);
        map[ks.e].emplace_back(ks.s);
        graph.emplace_back(ks);
        total += ks.v;
    }
}

int Find(int x)
{
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

bool Union(int x,int y)
{
    x = Find(x);
    y = Find(y);

    if(x == y) return false;

    visited[x] = true;
    visited[y] = true;
    parent[x] = y;
    return true;
}

bool BFS()
{
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(auto i : map[now])
        {
            if(visited[i]) continue;
            visited[i] = true;
            q.push(i);
        }
    }

    for(int i = 1; i <= n; i++)
        if(!visited[i]) return false;
    return true;
}

void SOLVE()
{
    if(!BFS())
    {
        cout << -1;
        return;
    }

    memset(visited,false,sizeof visited);
    sort(graph.begin(),graph.end(),[](KS a,KS b){return a.v<b.v;});
    for(int i = 1; i <= n; i++) parent[i] = i;

    ll ans = 0;
    for(auto &i : graph)
        if(Union(i.s,i.e)) ans += i.v;

    cout << total-ans;
}

int main()
{
    INPUT();
    SOLVE();
}