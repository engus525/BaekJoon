#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // cpp
using namespace std;

int g, p;
int gi[100001];
int parent[100001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> g >> p;
    for (int i = 1; i <= p; i++) cin >> gi[i];
}

int Find(int x)
{
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}

void SOLVE()
{

    // Union Find Init
    for (int i = 1; i <= g; i++) parent[i] = i;

    int ans = 0;

    for (int i = 1; i <= p; i++)
    {
        int G = Find(gi[i]);
        // No gate to dock.
        if (!G) break;

        // There's gate to docking
        ans++;
        Union(G, G - 1);
    }

    cout << ans;
}



int main()
{
    INPUT();

    SOLVE();

}

