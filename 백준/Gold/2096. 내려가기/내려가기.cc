#include <iostream>
#include <algorithm>
using namespace std;

int n;
int map[100'001][3];
int dp[2][3][2];
int dir[3][2] = {{-1,-1},{-1,0},{-1,1}};

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> map[i][j];
}

pair<int,int> setDP(int x, int y)
{

    int Max = -1; int Min = 2e9;

    for(int i = 0; i < 3; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if(0 <= ny && ny < 3)
        {
            Max = max(Max, dp[0][ny][0]);
            Min = min(Min, dp[0][ny][1]);
        }
    }

    return {Max + map[x][y],Min + map[x][y]};
}


void SOLVE()
{
    dp[1][0][0] = map[0][0]; dp[1][0][1] = map[0][0];
    dp[1][1][0] = map[0][1]; dp[1][1][1] = map[0][1];
    dp[1][2][0] = map[0][2]; dp[1][2][1] = map[0][2];

    for(int i = 1; i < n; i++)
    {
        dp[0][0][0] = dp[1][0][0]; dp[0][0][1] = dp[1][0][1];
        dp[0][1][0] = dp[1][1][0]; dp[0][1][1] = dp[1][1][1];
        dp[0][2][0] = dp[1][2][0]; dp[0][2][1] = dp[1][2][1];

        for(int j = 0; j < 3; j++)
        {
            pair<int,int> DP = setDP(i,j);
            dp[1][j][0] = DP.first;
            dp[1][j][1] = DP.second;
            //cout << "(" << DP.first << "," << DP.second << ") ";
        }
        //cout << '\n';
    }

    cout << max(max(dp[1][0][0],dp[1][1][0]),dp[1][2][0]) << " "
    << min(min(dp[1][0][1],dp[1][1][1]),dp[1][2][1]);

}

int main()
{
    INPUT();
    SOLVE();
}
