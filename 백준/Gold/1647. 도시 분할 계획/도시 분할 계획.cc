#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
struct KS
{
    int s,e,v;
};
vector<KS> graph;
int parent[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b,c; cin>>a>>b>>c;
        graph.push_back({a, b, c});
        graph.push_back({b,a,c});
    }
}

int Find(int x)
{
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if(x == y) return false;

    parent[x] = y;
    return true;
}

void SOLVE()
{
    for(int i = 1; i <= n; i++) parent[i] = i;
    sort(graph.begin(),graph.end(),
         [](KS a, KS b){return a.v < b.v;});

    int ans = 0; int maxV = -1;
    for(auto &i : graph)
    {
        if(Union(i.s,i.e))
            ans += i.v,
            maxV = max(maxV,i.v);
    }

    cout << ans - maxV;

}

int main()
{
    INPUT();
    SOLVE();
}