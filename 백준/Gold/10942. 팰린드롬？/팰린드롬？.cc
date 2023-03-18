#include <iostream>
#include <string>
using namespace std;

int n,m;
int seq[2010];
int dp[2010][2010];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> seq[i];
        dp[i][i] = 1;
    }
    cin >> m;
}


void SOLVE()
{

    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 1; j + i <= n; j++)
        {
            if(i == 1 && seq[j] == seq[j + i])
                dp[j][j + i] = 1;
            else if(seq[j] == seq[j + i] && dp[j + 1][j + i - 1] == 1)
                dp[j][j + i] = 1;
            else dp[j][j + i] = 0;
        }
    }


    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << '\n';
    }*/

    for(int i = 0; i < m; i++)
    {
        int s,e; cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}