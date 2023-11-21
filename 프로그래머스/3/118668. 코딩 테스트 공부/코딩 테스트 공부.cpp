#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

int dp[152][152];

int solution(int alp, int cop, vector<vector<int>> problems) {
    
    int dp[152][152];
    
    
    pii target = {alp,cop};
    
    
    fill(&dp[0][0],&dp[151][152],2e9); // 모든 값 가장 높게 초기화
    dp[alp][cop] = 0; // 시작하는 값은 당연히 0초로 초기화
    
    // 순회하여 각각의 max값을 찾아줌
    for(auto problem : problems){
        target.first = max(target.first,problem[0]);
        target.second = max(target.second,problem[1]);
    }
    
    // 기존의 alp와 cop가 가장 높은 값이라면 계산 필요없음
    if(target.first == alp && target.second == cop) return 0;
    
    for (int i = alp; i <= target.first; i++)
    {
        for (int j = cop; j <= target.second; j++)
        {
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            
            for(auto problem : problems){
                // 조건 만족시
                if(i >= problem[0] && j >= problem[1]){
                    // 기존 점수와 문제에서 얻은 점수의 합이 maxAlp를 넘지 못하게함
                    int nextA = min(target.first,problem[2]+i);
                    int nextC = min(target.second,problem[3]+j);
                    // 해당 문제를 풀었을 때의 점수와 비교
                    dp[nextA][nextC] = min(dp[nextA][nextC],dp[i][j]+problem[4]);
                }
            }
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    
    return dp[target.first][target.second];
}