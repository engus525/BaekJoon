#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int n,k;
int map[101][11];
bool visited[101][11];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};;

void INPUT()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 10; j++)
            scanf("%1d",&map[i][j]);
}


bool BFS(int x,int y)
{
    // size가 k 이상이면 폭발
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

            if(0 <= nx && nx < n && 0 <= ny && ny < 10)
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

    if(bomb.size() >= k)
    {
        for(int i = 0; i < bomb.size(); i++)
        {
            map[bomb[i].first][bomb[i].second] = 0;
        }
        return true;
    }
    return false;
}

void moveMooyo()
{
    for(int j = 0; j < 10; j++)
    {
        for(int i = n-2; i >= 0; i--)
        {
            if(map[i][j] != 0)
            {
                int idx = i;

                while(idx + 1 < n && map[idx + 1][j] == 0)
                {
                    map[idx + 1][j] = map[idx][j];
                    map[idx][j] = 0;
                    idx++;
                }
            }
        }
    }

}

void SOLVE()
{

    while(true)
    {
        // 연쇄
        bool erased = false;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 10; j++)
            {
                if(map[i][j] != 0)
                {
                    if(BFS(i,j)) erased = true;
                    memset(visited,false,sizeof visited);
                }
            }

        // 터진 무요가 없다면 끝
        if(!erased) break;

        // 아래로 떨어짐
        moveMooyo();
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 10; j++)
            cout << map[i][j];
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}