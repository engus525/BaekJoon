#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

string solution(vector<string> all, vector<string> pass) {
    
    multiset<string> allSet(all.begin(), all.end());
    for (auto passName : pass)
    {
        auto it = allSet.find(passName);
        allSet.erase(it);
    }
    
    string answer = "";
    for (auto ans : allSet) answer = ans;
    return answer;
}