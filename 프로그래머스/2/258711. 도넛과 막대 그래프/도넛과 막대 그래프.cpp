#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>

using namespace std;
#define N 1000001

vector<vector<int>> graph;
bool visited[N];
bool exist[N];
int in[N];
int n;

vector<int> ans(4);

// 정점 수, 간선 수
pair<int, int> bfs(int start)
{
    
    pair<int, int> rtn = {1, 0};
    queue<int> q;
    q.emplace(start);
    visited[start] = true;
    
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        
        
        for (int i = 0; i < graph[x].size(); i++)
        {
            int nx = graph[x][i];
            if (nx == ans[0]) continue;
            rtn.second++;
            
            if (visited[nx]) continue;
            rtn.first++;
            
            q.emplace(nx);
            visited[nx] = true;
        }
    }
    
    return rtn;
}

vector<int> solution(vector<vector<int>> edges) {
    
    graph.resize(N);
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
    
    // 막대 그래프 중간/끝 지점부터 일부만 방문하지 않도록 양방향 연결
    for (auto edge : edges)
    {
        if (edge[0] == ans[0] || edge[1] == ans[0]) continue;
        graph[edge[1]].emplace_back(edge[0]);
    }

    
    for (int i = 1; i <= n; i++)
    {
        if (!exist[i]) continue;
        if (ans[0] == i) continue;
        
        if (visited[i]) continue;
        auto [node, edge] = bfs(i);
        
        // 시작점으로 복귀 && 복귀와 동시에 queue 비어있음 -> 도넛
        if (2 * node == edge) ans[1]++;
        // 시작점 복귀 && 복귀 시점에 queue 남아있음 -> 8자
        else if (2 * node + 2 == edge ) ans[3]++;
        else ans[2]++;
    }
    
    
    return ans;
}