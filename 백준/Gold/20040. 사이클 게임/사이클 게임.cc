#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n,m;
int parent[500001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
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

    if(x < y) parent[x] = y;
    else parent[y] = x;
    return true;
}


void SOLVE()
{
    for(int i = 0; i < n; i++) parent[i] = i;

    for(int i = 1; i <= m; i++)
    {
        int a,b; cin >> a >> b;
        if(!Union(a,b))
        {
            cout << i;
            return;
        }
    }
    cout << 0;
}

int main()
{
    INPUT();
    SOLVE();
}