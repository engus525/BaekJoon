#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, vector<string>> M;
    for (int i = 0; i < clothes.size(); i++)
    {
        M[clothes[i][1]].emplace_back(clothes[i][0]);
    }
    
    for (auto it : M)
    {
        answer *= (it.second.size() + 1);
    }
    
    answer--;
    return answer;
}