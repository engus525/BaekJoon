#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
typedef long long ll;
ll cost[1001][1001];
struct KS
{
    int s,e;
    ll v;
};
vector<KS> graph;
int parent[1001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if(cost[i][j]) graph.push_back({i,j,cost[i][j]});
        }
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

    if(x > y) parent[x] = y;
    else parent[y] = x;
    return true;
}


void SOLVE()
{
    sort(graph.begin(), graph.end(),[](KS a,KS b){return a.v < b.v;});

    ll ans = 0;
    for(auto &i : graph)
        if(Union(i.s,i.e))
            ans += i.v;
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}