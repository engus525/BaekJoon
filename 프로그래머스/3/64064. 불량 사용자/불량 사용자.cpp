#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
vector<string> userV, banV;
vector<int> comb;
unordered_set<int> S;
bool visited[10];
int ans = 0;


void comp()
{
    for (int i = 0; i < comb.size(); i++)
    {
        string userName = userV[comb[i]];
        string banName = banV[i];
        
        if (userName.length() != banName.length()) return;
        
        for (int j = 0; j < banName.length(); j++)
        {
            if (banName[j] == '*') continue;
            if (userName[j] != banName[j]) return;
        }
    }
    
    vector<int> idxV;
    for (auto idx : comb)
    {
        idxV.emplace_back(idx);
        // cout << userV[idx] << " ";
    }
    sort(idxV.begin(), idxV.end());
    int val = 0;
    for (auto idx : idxV) val = val * 10 + idx;
    // cout << val << '\n';
    S.emplace(val);

    
    ans++;
}


void makeComb(int depth)
{
    if (depth == banV.size())
    {
        comp();
        return;
    }
    
    for (int i = 0; i < userV.size(); i++)
    {
        if (visited[i]) continue;
        
        comb.emplace_back(i);
        visited[i] = true;
        makeComb(depth + 1);
        comb.pop_back();
        visited[i] = false;
        
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    userV = user_id, banV = banned_id;
    
    
    makeComb(0);
    
    unordered_map<string, int> M;
    for (auto name : banV)
        M[name]++;
        
    for (auto [key, value] : M)
        ans /= value;
    
    return S.size();
}