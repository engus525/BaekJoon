#include <string>
#include <vector>

using namespace std;

bool visited[201];
vector<vector<int>> graph;

void dfs(int now)
{
    visited[now] = true;
    
    for (int i = 0; i < graph[now].size(); i++)
    {
        int next = graph[now][i];
        if (visited[next]) continue;
        
        dfs(next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!computers[i][j]) continue;
            graph[i].emplace_back(j);
            graph[j].emplace_back(i);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;
        answer++;
        dfs(i);
    }
    
    
    return answer;
}