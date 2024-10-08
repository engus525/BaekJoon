#include <iostream>
#include <cmath>
#include <queue>
#include <string>
#include <memory.h>
#include <map>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int dist[501][501];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 1e9;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        dist[a][b] = 1;
    }
}

void solution()
{
    for (int mid = 1; mid <= n; mid++)
    {
        for (int s = 1; s <= n; s++)
        {
            for (int e = 1; e <= n; e++)
            {
                if (dist[s][e] > dist[s][mid] + dist[mid][e])
                    dist[s][e] = dist[s][mid] + dist[mid][e];
            }
        }
    }

    int ans = 0;
    for (int s = 1; s <= n; s++)
    {
        bool all = true;
        for (int e = 1; e <= n; e++)
        {
            if (dist[s][e] == 0) continue;
            if (dist[s][e] == 1e9 && dist[e][s] == 1e9) all = false;
        }
        if (all) ans++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}