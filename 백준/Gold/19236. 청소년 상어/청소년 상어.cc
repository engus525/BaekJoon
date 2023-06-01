#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Fish
{
    int d;
    int x;
    int y;
    bool alive;
};
struct Shark
{
    int d;
    int x;
    int y;
};
Fish fish[20];
int map[4][4];
typedef pair<int, int> pii;
pii dir[8] = {{-1, 0}, {-1, -1},
              {0,  -1}, {1,  -1},
              {1,  0}, {1,  1},
              {0,  1}, {-1, 1}};
int ans = 0;

void INPUT()
{
    IAMFAST
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            int a, b;
            cin >> a >> b;
            fish[a] = {b - 1, i, j, true};
            map[i][j] = a;
        }
}

void Copy(int m1[4][4],int m2[4][4],Fish f1[20], Fish f2[20])
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            m1[i][j] = m2[i][j];

    for(int i = 1; i <= 16; i++) f1[i] = f2[i];
}

void moveFish()
{
    for(int id = 1; id <= 16; id++)
    {
        if(!fish[id].alive) continue;

        int x = fish[id].x;
        int y = fish[id].y;
        int d = fish[id].d;

        for(int i = 0; i < 8; i++)
        {
            int nd = (d+i) % 8;
            int nx = x + dir[nd].first;
            int ny = y + dir[nd].second;
            if(nx < 0 || nx > 3 || ny < 0 || ny > 3) continue;
            if(map[nx][ny] == -1) continue;

            if(map[nx][ny] == 0)
            {
                fish[id].x = nx;
                fish[id].y = ny;
                fish[id].d = nd;
                map[x][y] = 0;
                map[nx][ny] = id;
            }
            else
            {
                int targetId = map[nx][ny];
                swap(map[x][y],map[nx][ny]);
                fish[id].d = nd;
                //swap fish
                Fish temp = fish[id];
                fish[id].x = fish[targetId].x;
                fish[id].y = fish[targetId].y;
                fish[targetId].x = temp.x;
                fish[targetId].y = temp.y;
            }
            break;
        }

    }
}

void moveShark(Shark shark, int score)
{
    ans = max(ans,score);

    int cMap[4][4];
    Fish cFish[20];
    Copy(cMap,map,cFish,fish);

    moveFish();

    for(int i = 1; i < 4; i++)
    {
        int nx = shark.x + dir[shark.d].first * i;
        int ny = shark.y + dir[shark.d].second * i;


        if(nx < 0 || nx > 3 || ny < 0 || ny > 3) break;
        if(map[nx][ny] == 0) continue;
        int fishId = map[nx][ny];
        int nd = fish[fishId].d;

        map[shark.x][shark.y] = 0;
        map[nx][ny] = -1;
        fish[fishId].alive = false;

        moveShark({nd,nx,ny},score+fishId);

        map[shark.x][shark.y] = -1;
        map[nx][ny] = fishId;
        fish[fishId].alive = true;
    }
    Copy(map,cMap,fish,cFish);
}

void SOLVE()
{
    //init
    fish[map[0][0]].alive = false;
    int sharkD = fish[map[0][0]].d;
    ans = map[0][0];
    map[0][0] = -1;

    moveShark({sharkD,0,0},ans);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}