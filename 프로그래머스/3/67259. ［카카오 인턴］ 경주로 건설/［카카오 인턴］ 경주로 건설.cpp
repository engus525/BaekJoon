#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

int visited[26][26][4];
//동 서 남 북 0 1 2 3
pii dir[4] = {{0,1},
              {0,-1},
              {1,0},
              {-1,0}};
struct INFO
{
    int x, y, d, cost;
};

int getCost(int d, int nd)
{
    if (d == nd) return 100;
    else return 600;
}

int solution(vector<vector<int>> graph) {
    int answer = 2e9;
    
    int n = graph.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 4; k++)
            visited[i][j][k] = 2e9;
    
    queue<INFO> q;
    q.push({0,0,0,0});//동쪽 출발
    q.push({0,0,2,0});//남쪽 출발
    visited[0][0][0] = 0;
    visited[0][0][1] = 0;
    visited[0][0][2] = 0;
    visited[0][0][3] = 0;
    
    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        int cost = q.front().cost;
        q.pop();
        
        if (x == n - 1 && y == n - 1)
        {
            answer = min(answer, cost);
            continue;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            int nd = i;
            int nCost = getCost(d, nd);
            
            int newCost = cost + nCost;
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;//범위 초과
            if (visited[nx][ny][nd] < newCost) continue;//이미 더 싸게 방문
            if (graph[nx][ny]) continue;//벽
            
            //cout << x << " " << y << " to " << nx << " " << ny << " by " << newCost << '\n';
            visited[nx][ny][nd] = newCost;
            q.push({nx, ny, nd, newCost});
        }
    }
    
    //cout << "ans : " << answer;
    return answer;
}