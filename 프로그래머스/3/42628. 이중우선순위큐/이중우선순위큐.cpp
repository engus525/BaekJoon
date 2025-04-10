#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
map<int, int> M;

vector<int> solution(vector<string> v) {
    vector<int> answer;
    
    for (auto val : v)
    {
        char c = val[0];
        int num = stoi(val.substr(2));
        // cout << c << " " << num << '\n';
        
        if (c == 'I')
        {
            M[num]++;
        }
        else
        {
            if (M.empty()) continue;
            
            if (num == 1)
            {
                auto it = M.rbegin();
                // cout << "max : " << it->first << '\n';
                M[it->first]--;
                if (it->second == 0) M.erase(it->first);
            }
            else if (num == -1)
            {
                auto it = M.begin();
                // cout << "min : " << it->first << '\n';
                M[it->first]--;
                if (it->second == 0) M.erase(it->first);
            }
        }
    }
    
    if (M.empty()) return {0,0};
    return {M.rbegin()->first, M.begin()->first};
}