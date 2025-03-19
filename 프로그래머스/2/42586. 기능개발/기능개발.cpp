#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int,int> M;

vector<int> solution(vector<int> progressV, vector<int> speedV) {
    vector<int> answer;
    
    
    int minDeploy = 0;
    for (int i = 0; i < progressV.size(); i++)
    {
        int deploy = (100 - progressV[i]) / speedV[i];
        if ((100 - progressV[i]) % speedV[i]) deploy++;
        minDeploy = max(minDeploy, deploy);
        M[minDeploy]++;
    }
    
    for (auto it : M) answer.emplace_back(it.second);
    
    return answer;
}