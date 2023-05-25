#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
typedef pair<int,int> pii;
vector<pii> X;
vector<pii> Y;
vector<pii> Z;
struct KS
{
    int s,e,v;
};
vector<KS> graph;
int parent[100001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x,y,z; cin >>x>>y>>z;
        X.emplace_back(x,i);
        Y.emplace_back(y,i);
        Z.emplace_back(z,i);
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

    parent[x] = y;
    return true;
}

void setGraph()
{
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    sort(Z.begin(),Z.end());

    for(int i = 0 ; i < n-1; i++)
    {
        graph.push_back({X[i].second,X[i+1].second,X[i+1].first-X[i].first});
        graph.push_back({Y[i].second,Y[i+1].second,Y[i+1].first-Y[i].first});
        graph.push_back({Z[i].second,Z[i+1].second,Z[i+1].first-Z[i].first});
    }

    sort(graph.begin(),graph.end(),[](KS a,KS b){return a.v<b.v;});
}

void SOLVE()
{
    setGraph();

    for(int i = 0; i < n; i++) parent[i] = i;

    int ans = 0;
    for(auto &i : graph)
        if(Union(i.s,i.e)) ans += i.v;

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}