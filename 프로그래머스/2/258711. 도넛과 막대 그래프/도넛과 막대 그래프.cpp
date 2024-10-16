#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>

using namespace std;
vector<vector<int>> graph;
bool visited[1000001];
bool exist[1000001];
int in[1000001];
int n;

vector<int> ans(4);


pair<bool, bool> bfs(int start)
{
    unordered_set<int> nodeSet;
    
    pair<bool, bool> rtn = {false, false};
    queue<int> q;
    q.emplace(start);
    nodeSet.emplace(start);
    visited[start] = true;
    
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        
        // 8자 결합점
        if (in[x] == 2 && graph[x].size() == 2) rtn.second = true;
        
        for (int i = 0; i < graph[x].size(); i++)
        {
            int nx = graph[x][i];
            if (nx == start) rtn.first = true;
            if (visited[nx]) continue;
            
            q.emplace(nx);
            visited[nx] = true;
        }
    }
    
    if (!rtn.first)
    {
        if (in[start] == 0 && graph[start].size() <= 1) ans[2]++;
        for (auto node : nodeSet)
            visited[node] = false;
    }
    return rtn;
}

vector<int> solution(vector<vector<int>> edges) {
    
    graph.resize(1000001);
    for (auto edge : edges)
    {
        exist[edge[0]] = true, exist[edge[1]] = true;
        graph[edge[0]].emplace_back(edge[1]);
        in[edge[1]]++;
        n = max(n, max(edge[0], edge[1]));
    }
    
    for (int i = 1; i <= n; i++)
    {
        // 자신이 도착지인 곳이 없고 연결점이 2개 이상 -> 생성한 정점
        if (in[i] == 0 && graph[i].size() >= 2)
        {
            ans[0] = i;
            for (auto no : graph[i]) in[no]--;
            break;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (!exist[i]) continue;
        if (ans[0] == i) continue;
        
        // 막대 그래프에서 중간 지점 or 끝 지점부터 탐색한 경우
        if (graph[i].size() == 1 && visited[graph[i][0]])
        {
            visited[i] = true;
            continue;
        }
        
        if (visited[i]) continue;
        auto result = bfs(i);
        
        // 시작점으로 복귀 && 복귀와 동시에 queue 비어있음 -> 도넛
        if (result.first && !result.second) ans[1]++;
        // 시작점 복귀 && 복귀 시점에 queue 남아있음 -> 8자
        else if (result.first && result.second) ans[3]++;
    }
    
    
    return ans;
}