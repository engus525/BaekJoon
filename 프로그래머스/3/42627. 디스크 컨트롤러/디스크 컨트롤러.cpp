#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

struct comp
{
    bool operator()(const pii &a, const pii &b)
    {
        return a.second > b.second;
    }
};
priority_queue<pii, vector<pii>, comp> pq;
int nowTime = 0;


int solution(vector<vector<int>> v) {
    int ans = 0;
    sort(v.begin(), v.end());
    
    int vIdx = 0, nowTime = 0;
    while (vIdx < v.size() || !pq.empty())
    {
        for (int i = vIdx; i < v.size(); i++)
        {
            if (v[i][0] > nowTime) continue;;
            vIdx++;
            pq.emplace(v[i][0], v[i][1]);
        }
        
        if (!pq.empty())
        {
            auto [inTime, workTime] = pq.top();
            pq.pop();
            nowTime += workTime;
            ans += nowTime - inTime;
        }
        else
        {
            nowTime = v[vIdx][0];
        }
        
    }
    
    return ans / v.size();
}