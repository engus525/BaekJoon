#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
bool comp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}
priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end());
    
    for (auto target : targets)
    {
        int s = target[0], e = target[1];
        
        if (pq.empty() || pq.top() > s) pq.emplace(e);
        else if (pq.top() <= s)
        {
            answer++;
            while (!pq.empty()) pq.pop();
            pq.emplace(e);
        }
        
    }
    
    return answer;
}