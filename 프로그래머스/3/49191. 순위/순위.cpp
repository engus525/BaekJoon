#include <string>
#include <vector>
#include <memory.h>
#include <queue>
#include <iostream>

using namespace std;

bool visited[101];
vector<vector<int>> winGraph, loseGraph;

int bfs(int start, vector<vector<int>> &graph)
{
    int cnt = -1;
    queue<int> q;
    q.emplace(start);
    visited[start] = true;
    
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        cnt++;
        
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (visited[next]) continue;
            visited[next] = true;
            q.emplace(next);
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    winGraph.resize(n + 1);
    loseGraph.resize(n + 1);
    for (int i = 0; i < results.size(); i++)
    {
        int win = results[i][0], lose = results[i][1];
        winGraph[win].emplace_back(lose);
        loseGraph[lose].emplace_back(win);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof visited);
        int winCnt = bfs(i, winGraph);
        memset(visited, false, sizeof visited);
        int loseCnt = bfs(i, loseGraph);
        // cout << winCnt << " " << loseCnt << '\n';
        if (winCnt + loseCnt == n - 1) ans++;
    }
    
    return ans;
}