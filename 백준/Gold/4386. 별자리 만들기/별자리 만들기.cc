#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
typedef pair<double,double> pdd;
vector<pdd> pos;
struct KS
{
    int s,e;
    double v;
};
vector<KS> graph;
int parent[101];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        double a,b; cin >> a >> b;
        pos.emplace_back(a,b);
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

double getDist(pdd a,pdd b)
{
    return sqrt(pow(abs(a.first-b.first),2) +pow(abs(a.second-b.second),2));
}

void setGraph()
{
    for(int i = 0; i < pos.size()-1; i++)
        for(int j = i+1; j < pos.size(); j++)
            graph.push_back({i,j,getDist(pos[i],pos[j])});
}

void SOLVE()
{
    setGraph();

    for(int i = 1; i <= n; i++) parent[i] = i;

    sort(graph.begin(),graph.end(),
         [](KS a, KS b){return a.v < b.v;});

    double ans = 0;
    for(auto &i : graph)
        if(Union(i.s,i.e))
            ans += i.v;

    cout << fixed; cout.precision(2);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}