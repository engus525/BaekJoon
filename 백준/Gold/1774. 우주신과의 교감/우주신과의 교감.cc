#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
typedef pair<double,double> pdd;
vector<pdd> pos;
struct KS
{
    int s,e;
    double v;
};
vector<KS> graph;
int parent[1001];

int Find(int x);
bool Union(int x,int y);

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        double x,y; cin>>x>>y;
        pos.push_back({x, y});
    }
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 0; i < m; i++)
    {
        int x,y; cin >> x >> y;
        Union(x,y);
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

    if(x > y) parent[x] = y;
    else parent[y] = x;
    return true;
}

double getDist(int a,int b)
{
    pdd p1 = pos[a], p2 = pos[b];
    return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}

void setGraph()
{
    for(int i = 0; i < pos.size()-1; i++)
        for(int j = i+1; j < pos.size(); j++)
            graph.push_back({i+1, j+1, getDist(i, j)});

    sort(graph.begin(),graph.end(),[](KS a,KS b){return a.v<b.v;});
}

void SOLVE()
{
    setGraph();

    double ans = 0;
    for(auto &i : graph)
        if(Union(i.s,i.e)) ans += i.v;

    cout << fixed; cout.precision(2);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}