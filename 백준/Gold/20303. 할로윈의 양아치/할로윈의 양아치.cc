#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k;
vector<int> kid[30001];
vector<pair<int,int>> group;
bool visited[30001];
int candy[30001];
int dp[3001];


void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> candy[i];
    }
}

pair<int,int> setGroup(int x)
{
    int s = 1;
    int c = candy[x];
    visited[x] = true;

    for(int i = 0; i < kid[x].size(); i++)
    {
        if(!visited[kid[x][i]])
        {
            pair<int,int> size_candy = setGroup(kid[x][i]);
            s += size_candy.first;
            c += size_candy.second;
        }
    }
    return {s,c};
}


void SOLVE()
{

    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        kid[a].push_back(b);
        kid[b].push_back(a);
    }

    // 무리 설정
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            pair<int,int> size_candy = setGroup(i);
            group.push_back(size_candy);
        }
    }

    int ans = 0;
    dp[0] = 0;
    for(pair<int,int> sc : group)
    {
        for(int i = k - 1; i >= 0; i--)
        {
            if(i - sc.first >= 0)
            {
                dp[i] = max(dp[i], dp[i - sc.first] + sc.second);
                ans = max(ans,dp[i]);
            }
        }
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}