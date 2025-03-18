#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

int solution(vector<vector<int>> v) {
    
    pii ans = {0, 0};
    for (int i = 0; i < v.size(); i++)
    {
        ans.first = max(ans.first, max(v[i][0], v[i][1]));
        ans.second = max(ans.second, min(v[i][0], v[i][1]));
    }
    
    return ans.first * ans.second;
}