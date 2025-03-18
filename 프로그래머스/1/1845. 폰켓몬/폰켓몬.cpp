#include <vector>
#include <set>
#include <iostream>
using namespace std;

set<int> S;

int solution(vector<int> v)
{
    for (auto val : v) S.emplace(val);
    
    int answer = min(v.size() / 2, S.size());
    
    cout << min(v.size() / 2, S.size());
    
    return answer;
}