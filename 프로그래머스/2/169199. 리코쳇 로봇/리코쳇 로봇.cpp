#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

int visited[101][101];
char board[101][101];
int n, m;
pii s,e;
pii dir[4] = {{0,-1},
              {0,1},
              {-1,0},
              {1,0}};

bool outOfRange(int x, int y)
{
    return (x < 0 || y < 0 || x >= n || y >= m);
}

int BFS()
{
    queue<pii> q;
    q.emplace(s);
    visited[s.first][s.second] = 1;
    
    while (!q.empty())
    {
        auto [x,y] = q.front();
        //cout << x << " " << y << '\n';
        q.pop();
        
        if (e.first == x && e.second == y) return visited[x][y];
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (outOfRange(nx, ny)) continue;
            if (board[nx][ny] == 'D') continue;
            
            //벽이나 장애물 전까지 이동
            int tx = nx;
            int ty = ny;
            while (!outOfRange(tx, ty) && board[tx][ty] != 'D')
            {
                //cout << " -> " << tx << " " << ty << '\n';
                tx += dir[i].first;
                ty += dir[i].second;
            }
            
            tx -= dir[i].first;
            ty -= dir[i].second;
            if (!visited[tx][ty] && !outOfRange(tx, ty))
            {
                nx = tx;
                ny = ty;
                //cout << " to " << nx << " " << ny << '\n';
                q.emplace(nx, ny);
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }
    
    return 0;
}

int solution(vector<string> b) {
    int answer = 0;
    n = b.size(), m = b[0].length();
    //배열로 이동
    for (int i = 0; i < b.size(); i++)
        for (int j = 0; j < b[0].length(); j++)
        {
            board[i][j] = b[i][j];
            if (board[i][j] == 'R') s = {i, j};
            else if (board[i][j] == 'G') e = {i, j};
        }
    
    answer = BFS() - 1;
    
    return answer;
}