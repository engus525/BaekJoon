#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int m,n;
struct KS
{
    int s,e,v;
};
vector<KS> graph;
int parent[200001];

void INPUT()
{
    IAMFAST
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

void SOLVE()
{
    while(true)
    {
        int total = 0;
        graph.clear();
    
        //input
        cin >> m >> n; if(m == 0) break;
        for(int i = 0; i < n; i++)
        {
            KS ks; cin >> ks.s >> ks.e >> ks.v;
            graph.emplace_back(ks);
            total += ks.v;
        }

        //init
        sort(graph.begin(),graph.end(),[](KS a,KS b){return a.v<b.v;});
        for(int i = 0; i < m; i++) parent[i] = i;

        int ans = 0;
        for(auto &i : graph)
            if(Union(i.s,i.e)) ans += i.v;
        cout << total-ans << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}