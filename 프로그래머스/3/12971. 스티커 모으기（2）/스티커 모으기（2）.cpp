#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp1[100'001][2];
int dp2[100'001][2];


int solution(vector<int> v) {
    if (v.size() == 1) return v[0];
    int answer = 0;
    
    dp1[0][1] = v[0];
    for (int i = 1; i < v.size() - 1; i++)
    {
        dp1[i][0] = max(dp1[i - 1][0], dp1[i - 1][1]);
        dp1[i][1] = dp1[i - 1][0] + v[i];
        answer = max(dp1[i][0], dp1[i][1]);
    }
    
    dp2[0][1] = v.back();
    for (int i = v.size() - 1; i > 0; i--)
    {
        dp2[i][0] = max(dp2[i + 1][0], dp2[i + 1][1]);
        dp2[i][1] = dp2[i + 1][0] + v[i];
        answer = max(answer, max(dp2[i][0], dp2[i][1]));
    }
    
    return answer;
}