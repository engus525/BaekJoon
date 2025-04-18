#include <string>
#include <iostream>
using namespace std;

int x = 0, y = 0;
int visited[15][15][15][15];

pair<int,int> getNextPos(char dir)
{
    if (dir == 'U') return {x - 1, y};
    if (dir == 'L') return {x, y - 1};
    if (dir == 'R') return {x, y + 1};
    if (dir == 'D') return {x + 1, y};
}

int solution(string dirs) {
    int ans = 0;
    
    for (auto dir : dirs)
    {
        auto [nx, ny] = getNextPos(dir);
        if (nx < -5 || ny < -5 || nx > 5 || ny > 5) continue;
        
        if (!visited[x + 5][y + 5][nx + 5][ny + 5] || !visited[nx + 5][ny + 5][x + 5][y + 5])
            ans++;
        visited[x + 5][y + 5][nx + 5][ny + 5] = true;
        visited[nx + 5][ny + 5][x + 5][y + 5] = true;
        // cout << x << "," << y << " to " << nx << "," << ny << '\n';
        x = nx, y = ny;
        
    }
    
    return ans;
}