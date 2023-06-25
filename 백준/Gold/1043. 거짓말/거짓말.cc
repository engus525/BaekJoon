#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n,m,k;
bool truth[51];
vector<int> party[51];
int parent[51];

void INPUT()
{
    IAMFAST
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int t; cin >> t;
        truth[t] = true;
    }
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

    if(truth[x]) parent[y] = x;
    else parent[x] = y;
}

void SOLVE()
{
    for(int i = 1; i <= n; i++) parent[i] = i;

    for(int i = 0; i < m; i++)
    {
        int t; cin >> t;
        while(t--)
        {
            int num; cin >> num;
            party[i].emplace_back(num);
        }

        for(int j = 1; j < party[i].size(); j++)
            Union(party[i][0],party[i][j]);
    }

    for(int i = 1; i <= n; i++) parent[i] = Find(i);

    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        bool canLie = true;
        for(auto &p : party[i])
            if(truth[parent[p]])
                canLie = false;
        if(canLie) ans++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}