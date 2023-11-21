#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

int dp[152][152];

int solution(int alp, int cop, vector<vector<int>> problems) {
    
    pii target = {alp, cop};
    
    for(int i = 0; i <= 150; i++)
        for (int j = 0; j <= 150; j++)
            dp[i][j] = 2e9;
    dp[alp][cop] = 0;
    
    for(auto &p : problems)
    {
        target.first = max(target.first, p[0]);
        target.second = max(target.second, p[1]);
    }
    
    if(target.first == alp && target.second == cop) return 0;
    
    for (int i = alp; i <= target.first; i++)
    {
        for (int j = cop; j <= target.second; j++)
        {
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            
            for(auto &p : problems)
            {
                if(i < p[0] || j < p[1]) continue;
                

                int nx = min(target.first,p[2] + i);
                int ny = min(target.second,p[3] + j);

                dp[nx][ny] = min(dp[nx][ny],dp[i][j] + p[4]);
            }
        }
    }
    
    return dp[target.first][target.second];
}