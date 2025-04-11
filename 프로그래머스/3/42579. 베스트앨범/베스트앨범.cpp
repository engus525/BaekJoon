#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
unordered_map<string, int> cntM;
unordered_map<string, vector<pair<int,int>>> numM;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for (int i = 0; i < genres.size(); i++)
    {
        cntM[genres[i]] += plays[i];
        numM[genres[i]].emplace_back(plays[i], i);
    }
    
    vector<pair<string, int>> v(cntM.begin(), cntM.end());
    sort(v.begin(), v.end(), [](auto &a, auto &b)
         {
             return a.second > b.second;
         });
    
    for (auto &[key, value] : numM) 
        sort(value.begin(), value.end(), [](auto &a, auto &b)
             {
                 return a.first > b.first;
             });
    
//     for (auto [key, value] : numM) 
//     {
//         for (auto val : value) cout << val.second << " ";
//         cout << '\n';
//     }
    
    
    for (auto val : v)
    {
        // for (auto num : numM[val.first]) answer.emplace_back(num);
        for (int i = 0; i < min(2, int(numM[val.first].size())); i++)
            answer.emplace_back(numM[val.first][i].second);
    }
    
    return answer;
}