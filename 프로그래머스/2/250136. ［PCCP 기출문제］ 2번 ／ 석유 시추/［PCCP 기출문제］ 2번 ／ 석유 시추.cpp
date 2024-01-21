#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;
typedef pair<int,int> pii;
bool visited[501][501];
vector<vector<int>> land;
int n, m;
pii dir[4] = {{0, -1},
              {0, 1},
              {-1, 0},
              {1, 0}
                    };
set<pii> pos;
map<int, int> cnt;
int num = 1;

int DFS(int x, int y, int size)
{
    if (visited[x][y]) return 0;
    pos.insert({x,y});
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visited[nx][ny]) continue;
        if (land[nx][ny] == 0) continue;
        
        land[x][y] += DFS(nx, ny, size + 1);
    }
    
    return land[x][y];
}

int solution(vector<vector<int>> l) {
    land = l;
    n = land.size();
    m = land[0].size();
    int answer = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && land[i][j])
            {
                DFS(i, j, 0);
                cnt[num] = land[i][j];
                for (auto p : pos)
                    land[p.first][p.second] = num;
                pos.clear();
                num++;
            }
        }
    }
    

    for (int i = 0; i < m; i++)
    {
        int temp = 0;
        set<int> block;
        for (int j = 0; j < n; j++)
            if (land[j][i])
                block.insert(land[j][i]);
        
        for (auto b : block)
            temp += cnt[b];
        //cout << temp << '\n';
        answer = max(answer, temp);
    } 
    
    return answer;
}