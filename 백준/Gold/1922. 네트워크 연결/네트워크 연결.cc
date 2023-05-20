#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int a,b,c;
struct KS
{
    int s,e,v;
};
bool comp(KS x, KS y)
{
    return x.v < y.v;
}
vector<KS> v;
int parent[1001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v.push_back({a, b, c});
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

    if(x == y) return true;

    parent[x] = y;
    return false;
}

void SOLVE()
{
    sort(v.begin(),v.end(),comp);

    for(int i = 1; i <= n; i++) parent[i] = i;

    int ans = 0;
    for(int i = 0; i < m; i++)
        if(!Union(v[i].s, v[i].e))
            ans += v[i].v;
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}