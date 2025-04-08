#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
vector<vector<int>> graph;
int dist[100'001];

void bfs(int start)
{
    queue<int> q;
    q.emplace(start);
    dist[start] = 0;
    
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (dist[next] != -1) continue;
            
            q.emplace(next);
            dist[next] = dist[now] + 1;
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    graph.resize(n + 1);
    for (auto road : roads)
    {
        graph[road[0]].emplace_back(road[1]);
        graph[road[1]].emplace_back(road[0]);
    }
    
    for (int i = 1; i <= n; i++) dist[i] = -1;
    bfs(destination);
    
    for (auto source : sources) answer.emplace_back(dist[source]);
    return answer;
}