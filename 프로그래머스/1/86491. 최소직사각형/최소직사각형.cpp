#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

int solution(vector<vector<int>> sizes) {
    vector<vector<int>> v;
    for (auto size : sizes)
    {
        v.emplace_back(size);
        v.push_back({size[1], size[0]});
    }
    
    pii ans = {v[0][0], v[0][1]};
    for (int i = 2; i < v.size(); i += 2)
    {
        
        pii ans1 = {max(v[i][0], ans.first), max(v[i][1], ans.second)};
        pii ans2 = {max(v[i + 1][0], ans.first), max(v[i + 1][1], ans.second)};
        ans = (ans1.first * ans1.second > ans2.first * ans2.second) ?
            ans2 : ans1;
        
    }
    
    
    return ans.first * ans.second;
}