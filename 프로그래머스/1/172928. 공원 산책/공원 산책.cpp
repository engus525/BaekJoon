#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;
pii dir[4] = {{-1,0},//N
              {1,0},//S
              {0,-1},//W
              {0,1}};//E

vector<vector<char>> graph;
int n, m;

int toD(char c)
{
    if (c == 'N') return 0;
    if (c == 'S') return 1;
    if (c == 'W') return 2;
    if (c == 'E') return 3;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x = 0, y = 0;
    
    n = park.size(), m = park[0].length();
    
    graph.resize(n + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            graph[i].emplace_back(park[i][j]);
            if (park[i][j] == 'S') x = i, y = j;
        }
    
    for (auto r : routes)
    {
        int d = toD(r[0]);
        int cnt = r[2] - '0';
        //cout << d << " " << cnt << '\n';
        
        int nx = x + cnt * dir[d].first;
        int ny = y + cnt * dir[d].second;
        //cout << "To : " << nx << " " << ny << '\n';
        
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        
        int dx = dir[d].first, dy = dir[d].second;
        bool canPass = true;
        for (int i = 1; i <= cnt; i++)
        {
            int tx = x + i * dx;
            int ty = y + i * dy;
            if (graph[tx][ty] == 'X')
            {
                canPass = false;
                break;
            }
        }
        
        if (!canPass) continue;
        x = nx, y = ny;
    }

    
    
    return {x,y};
}