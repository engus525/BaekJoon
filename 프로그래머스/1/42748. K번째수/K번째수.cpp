#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> v, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++)
    {
        int s = commands[i][0];
        int e = commands[i][1];
        int idx = commands[i][2];
        
        vector<int> copyV(v.begin() + s - 1, v.begin() + e);
        sort(copyV.begin(), copyV.end());
        answer.emplace_back(copyV[idx - 1]);
        
    }
    
    return answer;
}