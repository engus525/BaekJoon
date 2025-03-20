#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

vector<vector<int>> graph;
int dist[20001];
int maxDist = 0;

void bfs()
{
    queue<int> q;
    q.emplace(1);
    dist[1] = 0;
    
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (dist[next] != -1) continue;
            
            dist[next] = dist[now] + 1;
            maxDist = max(maxDist, dist[next]);
            q.emplace(next);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    memset(dist, -1, sizeof dist);
    graph.resize(n + 1);
    for (int i = 0; i < edge.size(); i++)
    {
        int s = edge[i][0], e = edge[i][1];
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }
    
    bfs();
    
    for (int i = 1; i <= n; i++)
        if (dist[i] == maxDist)
            answer++;
    return answer;
}