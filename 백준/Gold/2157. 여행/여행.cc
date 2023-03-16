#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m,k;
typedef pair<int,int> pii;
vector<pii> graph[305];
int dp[305][305];

void INPUT()
{
    IAMFAST
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        if(a < b) graph[a].emplace_back(b,c);
    }
}

void SOLVE()
{
    //Init
    for(int i = 1; i <= n+1; i++)
        for(int j = 1; j <= n+1; j++)
            dp[i][j] = -1;

    for(int i = 0; i < graph[1].size(); i++)
        dp[graph[1][i].first][2] =
                max(dp[graph[1][i].first][2],graph[1][i].second);

    //DP
    for(int cnt = 2; cnt <= m; cnt++)
    {
        for(int now = 1; now <= n; now++)
        {
            for(int j = 0; j < graph[now].size(); j++)
            {
                int next = graph[now][j].first;
                int dist = graph[now][j].second;
                if(dp[now][cnt] == -1) continue;

                dp[next][cnt+1] = max(dp[next][cnt+1],dp[now][cnt]+dist);
            }
        }
    }

    int ans = 0;
    for(int i = 2; i <= m; i++)
        ans = max(ans,dp[n][i]);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}