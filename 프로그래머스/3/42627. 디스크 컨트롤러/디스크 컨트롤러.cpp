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
    while (vIdx < v.size())
    {
        for (int i = vIdx; i < v.size(); i++)
        {
            if (v[i][0] > nowTime) break;
            vIdx++;
            pq.emplace(v[i][0], v[i][1]);
        }
        
        if (vIdx < v.size() && pq.empty())
        {
            // cout << "continue at " << nowTime << '\n';
            nowTime = v[vIdx][0];
            continue;
        }
        
        // cout << "qSize : " << pq.size() << '\n';
        auto [inTime, workTime] = pq.top();
        // cout << "NOW : " << nowTime << " => ";
        // cout << inTime << " , " << workTime << '\n';
        // cout << "vIdx : " << vIdx << '\n';
        pq.pop();
        nowTime += workTime;
        ans += nowTime - inTime;
    }
    
    while (!pq.empty())
    {
        auto [inTime, workTime] = pq.top();
        // cout << "NOW : " << nowTime << " => ";
        // cout << inTime << " , " << workTime << '\n';
        // cout << "vIdx : " << vIdx << '\n';
        pq.pop();
        nowTime += workTime;
        ans += nowTime - inTime;
    }
    
    return ans / v.size();
}