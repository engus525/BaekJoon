#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int t,n;
string f1,f2;
int parent[200001];
int nSize[200001];

void INPUT()
{
    IAMFAST
    cin >> t;
}

int Find(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if(x == y) return;

    if(x < y) swap(x,y);
    nSize[x] += nSize[y];
    parent[y] = x;
}

void SOLVE()
{
    while(t--)
    {
        unordered_map<string,int> network;
        cin >> n;
        for(int i = 1; i <= 2*n; i++) parent[i] = i, nSize[i] = 1;

        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> f1 >> f2;
            if(network.find(f1) == network.end())
                network.insert({f1,++cnt});
            if(network.find(f2) == network.end())
                network.insert({f2,++cnt});

            Union(network[f1],network[f2]);

            cout << max(nSize[Find(network[f1])],
                        nSize[Find(network[f2])]) << '\n';
        }
    }
}

int main()
{
    INPUT();
    SOLVE();
}