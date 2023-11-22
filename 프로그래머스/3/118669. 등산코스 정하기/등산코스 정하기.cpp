#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;


int minIntensity[500001];
bool isSummit[50001];
vector<vector<pii>> graph;
queue<pii> q;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    int ansGate = 1e9, ansIntensity = 1e9;
    graph.resize(n + 1);
    for (auto &p : paths)
    {
        graph[p[0]].emplace_back(p[1],p[2]);
        graph[p[1]].emplace_back(p[0],p[2]);
    }
    
    for (int i = 1; i <= n; i++) minIntensity[i] = 1e9;
    
    for (auto &s: summits) isSummit[s] = true;
    for (auto &g: gates) minIntensity[g] = -1, q.emplace(0,g);
    
    
    while(!q.empty())
    {
        auto [maxD, now] = q.front();
        q.pop();
        
        if (maxD > ansIntensity) continue;
        if (isSummit[now])
        {
            if (maxD < ansIntensity)
            {
                ansGate = now;
                ansIntensity = maxD;
            }
            else if (maxD == ansIntensity && ansGate > now)
                ansGate = now;
            continue;
        }
        
        
        for (int i = 0; i < graph[now].size(); i++)
        {
            auto [next, d2] = graph[now][i];
            
            if (max(maxD, d2) >= minIntensity[next]) continue;
            
            minIntensity[next] = max(maxD, d2);
            q.emplace(minIntensity[next], next);
            
        }
        
    }
    
    
    return {ansGate, ansIntensity};
}