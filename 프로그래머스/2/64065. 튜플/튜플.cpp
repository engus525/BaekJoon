#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
bool visited[100001];
bool comp(vector<int> a, vector<int> b) {
    return a.size() < b.size(); 
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> v;
    vector<int> temp;
    string token;
    for (int i = 2; i < s.length() - 1; i++)
    {
        char c = s[i];
        
        if ('0' <= c && c <= '9') token += c;
        else if (c == ',' && token != "")
        {
            temp.emplace_back(stoi(token));
            token = "";
        }
        else if (c == '}' && token != "")
        {
            temp.emplace_back(stoi(token));
            v.emplace_back(temp);
            temp.clear();
            token = "";
        }
    }
    
    sort(v.begin(), v.end(), comp);
    
    for (auto i : v)
        for (auto j : i)
            if (!visited[j])
                answer.emplace_back(j),
                visited[j] = true;
    
        
    return answer;
}