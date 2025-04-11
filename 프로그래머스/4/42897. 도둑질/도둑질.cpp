#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[1'000'001];


int solution(vector<int> v) {
    int answer = 0;
    
    dp[0] = dp[1] = v[0];
    for (int i = 2; i < v.size() - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
    answer = dp[v.size() - 2];
    
    
    dp[0] = 0;
    dp[1] = v[1];
    for (int i = 2; i < v.size(); i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
    answer = max(answer, dp[v.size() - 1]);
    
    return answer;
}