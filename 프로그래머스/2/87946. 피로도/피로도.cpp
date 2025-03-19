#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int start, now;
bool visited[10];
vector<int> order;
vector<vector<int>> v;
int answer = 0;

void go()
{
    // cout << "Go!!!!\n";
    int ans = 0;
    now = start;
    for (int i = 0; i < v.size(); i++)
    {
        if (now < v[order[i]][0]) break;
        // cout << v[order[i]][1] << '\n';
        
        now -= v[order[i]][1];
        ans++;
    }
    answer = max(answer, ans);
}

void comb()
{
    if (order.size() == v.size())
    {
        go();
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        if (visited[i]) continue;
        
        order.emplace_back(i);
        visited[i] = true;
        comb();
        order.pop_back();
        visited[i] = false;
    }
    
}

int solution(int k, vector<vector<int>> dun) {
    v = dun;
    start = k;
    
    comb();
    
    return answer;
}