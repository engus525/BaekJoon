#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> orders;

set<string> S;
map<string, int> M;
bool visited[11];
int eachCnt[11];
int minCnt, maxCnt;

string sortValue(string value)
{
    string result;
    vector<char> temp;
    for (auto v : value)
        temp.emplace_back(v);
    sort(temp.begin(), temp.end());
    for (auto t : temp)
        result += t;
    return result;
}

void setComb(int start, string value, string order)
{
    if (value.length() > maxCnt) return;
    if (minCnt <= value.length() && value.length() <= maxCnt)
    {
        value = sortValue(value);
        if (M.find(value) == M.end()) M[value] = 1;
        else M[value]++;
        //cout << value << " " << M[value] << '\n';
    }
    
    for (int i = start; i < order.length(); i++)
    {
        value += order[i];
        setComb(i + 1, value,order);
        value.pop_back();
    }
    
}

vector<string> solution(vector<string> o, vector<int> course) {
    orders = o;
    vector<string> answer;
    minCnt = course[0], maxCnt = course.back();
    
    for (auto order : orders)
    {
        //cout << "\n------\n";
        setComb(0,"", order);
    }
    
    //조합 갯수별 최대 갯수
    for (auto m : M)
    {
        int cnt = m.first.length();
        eachCnt[cnt] = max(eachCnt[cnt], m.second);
    }
    
    set<string> ans;
    for (auto c : course)
    {
        for (auto m : M)
        {
            if (m.second < 2) continue;
            if (m.first.length() != c) continue;
            
            if (m.second == eachCnt[m.first.length()])
            {
                ans.insert(m.first);
            }
            
        }
        
    }
    
    for (auto a : ans) answer.emplace_back(a);
    return answer;
}