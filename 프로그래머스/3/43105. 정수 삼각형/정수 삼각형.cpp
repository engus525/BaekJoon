#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> graph) {
    int answer = 0;
    
    dp[0][0] = graph[0][0];
    for (int i = 1; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            dp[i][j] = graph[i][j] +
                max(dp[i - 1][max(0, j - 1)], dp[i - 1][j]);
        }
    }
    
    
    return *max_element(dp[graph.size() - 1],
                        dp[graph.size() - 1] + graph.size());
}