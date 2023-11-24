#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> M;

bool hadAll()
{
    for (auto &i : M)
        if (!i.second) return false;
    return true;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    for (auto &g : gems) M.insert({g, 0});
    
    int l = 0, r = 0;
    M[gems[0]] = 1;
    
    int minLen = 2e9;
    int cnt = 1;
    while (l <= r && r < gems.size())
    {
        bool all = hadAll();
        
        if (cnt == M.size())
        {
            if (r - l + 1 < minLen) minLen = r - l + 1, answer[0] = l + 1, answer[1] = r + 1;
            M[gems[l]]--;
            if (l < gems.size() && M[gems[l]] == 0) cnt--;
            l++;
        }
        else
        {
            r++;
            if (r < gems.size())
            {
                M[gems[r]]++;
                if (M[gems[r]]  == 1) cnt++;
            }
                
        }
        
    }
    
    
    return answer;
}