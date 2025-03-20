#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    dp[1][1] = 1;
    for (auto no : puddles) dp[no[1]][no[0]] = -1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1) continue;
            if (dp[i][j] == -1) continue;
            int left = (dp[i][j - 1] == -1) ? 0 : dp[i][j - 1];
            int up = (dp[i - 1][j] == -1) ? 0 : dp[i - 1][j];
            
            dp[i][j] = (left + up) % 1'000'000'007;
        }
    }
    
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    
    return dp[n][m];
}