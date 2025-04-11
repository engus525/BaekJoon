#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
unordered_map<string, int> cntM;
unordered_map<string, vector<int>> numM;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for (int i = 0; i < genres.size(); i++)
    {
        cntM[genres[i]] += plays[i];
        numM[genres[i]].emplace_back(i);
    }
    
    vector<pair<string, int>> v(cntM.begin(), cntM.end());
    sort(v.begin(), v.end(), [](auto &a, auto &b)
         {
             return a.second > b.second;
         });
    
    for (auto &[key, value] : numM) 
        sort(value.begin(), value.end(), [&plays](auto &a, auto &b)
             {
                 return plays[a] > plays[b];
             });
    
    
    for (auto val : v)
        for (int i = 0; i < min(2, int(numM[val.first].size())); i++)
            answer.emplace_back(numM[val.first][i]);
    
    return answer;
}