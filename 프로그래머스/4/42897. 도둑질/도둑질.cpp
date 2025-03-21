#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp1[1'000'001][2];
int dp2[1'000'001][2];


int solution(vector<int> money) {
    int answer = 0;
    
    dp1[0][1] = money[0];
    for (int i = 1; i < money.size() - 1; i++)
    {
        dp1[i][0] = max(dp1[i - 1][0], dp1[i - 1][1]);
        dp1[i][1] = dp1[i - 1][0] + money[i];
        // cout << dp1[i][0] << " " << dp1[i][1] << '\n';
        answer = max(dp1[i][0], dp1[i][1]);
    }
    
    dp2[0][1] = money[0];
    for (int i = money.size() - 1; i > 0; i--)
    {
        dp2[i][0] = max(dp2[i + 1][0], dp2[i + 1][1]);
        dp2[i][1] = dp2[i + 1][0] + money[i];
        // cout << dp2[i][0] << " " << dp2[i][1] << '\n';
        answer = max(answer, max(dp2[i][0], dp2[i][1]));
    }
    
    
    return answer;
}