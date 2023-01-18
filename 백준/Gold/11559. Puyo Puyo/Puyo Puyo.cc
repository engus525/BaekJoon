#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

char map[13][7];
bool visited[13][7];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};;

void INPUT()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 6; j++)
            scanf("%1s",&map[i][j]);
}


bool BFS(int x,int y)
{
    // size가 4 이상이면 폭발
    vector<pair<int,int>> bomb;

    queue<pair<int,int>> q;
    bomb.push_back({x,y});
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(0 <= nx && nx < 12 && 0 <= ny && ny < 6)
            {
                if(!visited[nx][ny] && map[nx][ny] == map[x][y])
                {
                    bomb.push_back({nx,ny});
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    if(bomb.size() >= 4)
    {
        for(int i = 0; i < bomb.size(); i++)
        {
            map[bomb[i].first][bomb[i].second] = '.';
        }
        return true;
    }
    return false;
}

void movePuyo()
{
    for(int j = 0; j < 6; j++)
    {
        for(int i = 10; i >= 0; i--)
        {
            if(map[i][j] != '.')
            {
                int idx = i;

                while(idx + 1 < 12 && map[idx + 1][j] == '.')
                {
                    map[idx + 1][j] = map[idx][j];
                    map[idx][j] = '.';
                    idx++;
                }
            }
        }
    }

}

void SOLVE()
{
    int ans = 0;

    while(true)
    {
        // 연쇄
        bool erased = false;
        for(int i = 0; i < 12; i++)
            for(int j = 0; j < 6; j++)
            {
                if(map[i][j] != '.')
                {
                    if(BFS(i,j)) erased = true;
                    memset(visited,false,sizeof visited);
                }
            }

        // 터진 뿌요가 있다면 1연쇄 추가
        if(erased) ans++;
        else break;

        // 아래로 떨어짐
        movePuyo();
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}