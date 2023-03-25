#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int dist[101][101];

void INPUT()
{
    IAMFAST
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = 1e9;
        }

    for(int i = 1; i <= m; i++)
    {
        int a,b,c; cin>>a>>b>>c;
        if(dist[a][b] > c) dist[a][b] = c;
    }
}

void SOLVE()
{

    for(int mid = 1; mid <= n; mid++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dist[i][j] < dist[i][mid]+dist[mid][j]) continue;
                dist[i][j] = dist[i][mid]+dist[mid][j];
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dist[i][j] == 1e9) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}