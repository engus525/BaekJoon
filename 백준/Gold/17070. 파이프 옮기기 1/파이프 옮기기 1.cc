#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
int n;
int home[17][17];
vector<int> dp[17][17]; //원소 : 가로 1, 세로 2, 대각 3

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> home[i][j];
}

void checkL(int x,int y)
{// 왼쪽 지점에 파이프 끝이 가로or대각이면 현재 지점에 가로로 옮겨짐
    if(!dp[x][y-1].empty())
    {
        for(int i = 0; i < dp[x][y - 1].size(); i++)
        {
            if(dp[x][y - 1][i] != 2)
                if(home[x][y] != 1)
                    dp[x][y].push_back(1);
        }
    }
}

void checkLU(int x,int y)
{// 왼쪽위 대각 지점에 파이프 끝이 존재하면 현재 지점에 대각으로 옮겨짐
    if(!dp[x - 1][y-1].empty())
    {
        for(int i = 0; i < dp[x - 1][y - 1].size(); i++)
        {
            if(home[x][y] != 1 && home[x][y - 1] != 1
            && home[x - 1][y] != 1)
                dp[x][y].push_back(3);
        }
    }
}

void checkU(int x,int y)
{// 윗 지점에 파이프 끝이 세로or대각이면 현재 지점에 세로로 옮겨짐
    if(!dp[x - 1][y].empty())
    {
        for(int i = 0; i < dp[x - 1][y].size(); i++)
        {
            if(dp[x - 1][y][i] != 1)
                if(home[x][y] != 1)
                    dp[x][y].push_back(2);
        }
    }
}

void SOLVE()
{
    // 가장 처음에 파이프는 가로 방향으로 (1,1)(1,2)를 차지한다.
    dp[1][2].push_back(1);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            checkL(i,j); // 왼쪽
            checkLU(i,j); // 왼쪽 위
            checkU(i,j); // 위
        }
    }

    cout << dp[n][n].size();
}

int main()
{
    INPUT();
    SOLVE();
}
