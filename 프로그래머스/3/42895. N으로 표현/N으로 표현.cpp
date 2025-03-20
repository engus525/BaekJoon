#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

unordered_set<int> dp[9];


int solution(int N, int number) {
    
    dp[1].emplace(N);
    if (N == number) return 1;
    
    dp[2].emplace(N * 10 + N);
    dp[2].emplace(N + N);
    dp[2].emplace(N - N);
    dp[2].emplace(N * N);
    dp[2].emplace(N / N);
    if (dp[2].find(number) != dp[2].end()) return 2;
    
    for (int i = 3; i <= 8; i++)
    {
        string str;
        for (int cnt = 0; cnt < i; cnt++) str += N + '0';
        dp[i].emplace(stoi(str));
        for (int l = 1; l <= i / 2; l++)
        {
            for (auto x : dp[l])
            {
                for (auto y : dp[i - l])
                {
                    dp[i].emplace(x + y);
                    dp[i].emplace(x - y);
                    dp[i].emplace(x * y);
                    if (y) dp[i].emplace(x / y);
                    dp[i].emplace(y - x);
                    if (x) dp[i].emplace(y / x);
                }
            }
            
            if (dp[i].find(number) != dp[i].end()) return i;
        }
    }
    
    return -1;
}