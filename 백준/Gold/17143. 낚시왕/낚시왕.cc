#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r,c,m;
struct Shark
{
    int x;
    int y;
    int speed;
    int direction;
    int size;
};
vector<Shark> S;
int map[101][101];

int ans = 0;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> m;
    for(int i = 0; i < m; i++)
    {
        int x,y,s,d,z; cin>>x>>y>>s>>d>>z;
        S.push_back({x,y,s,d,z});
        map[x][y]++;
    }
}

void catchShark(int f)
{
    for(int i = 1; i <= r; i++)
        if(map[i][f])
        {
            for(int j = 0; j < S.size(); j++)
            {
                if(S[j].x == i && S[j].y == f)
                {
                    ans += S[j].size;
                    S.erase(S.begin() + j);
                    map[i][f] = 0;
                    return;
                }
            }
        }
}

Shark goUD(int idx)
{
    int dir = S[idx].direction;
    int dist = S[idx].speed % (2*(r-1)); // 이동할 칸의 수 최적화
    int x = S[idx].x, y = S[idx].y; // 현재 위치
    while(dist--)
    {
        if(dir == 1)
        {
            if(x == 1)
            {
                dir = 2;
                x++;
                continue;
            }x--;
        }
        else if(dir == 2)
        {
            if(x == r)
            {
                dir = 1;
                x--;
                continue;
            }x++;
        }
    }

    return {x,y,S[idx].speed,dir,S[idx].size};
}

Shark goLR(int idx)
{
    int dir = S[idx].direction;
    int dist = S[idx].speed % (2*(c-1)); // 이동할 칸의 수 최적화
    int x = S[idx].x, y = S[idx].y;

    while(dist--)
    {
        if(dir == 3)
        {
            if(y == c)
            {
                dir = 4;
                y--;
                continue;
            }y++;
        }
        else if(dir == 4)
        {
            if(y == 1)
            {
                dir = 3;
                y++;
                continue;
            }y--;
        }
    }

    return {x,y,S[idx].speed,dir,S[idx].size};
}

void moveShark()
{
    int sSize = S.size();
    for(int i = 0; i < sSize; i++)
    {
        Shark s;
        // 방향이 1이나 2이면 위아래로 움직임
        if(S[i].direction <= 2) s = goUD(i);
        else s = goLR(i);

        // 이동한 위치에 삽입
        S.push_back(s);
        map[s.x][s.y]++;
        // 처음 위치에서 제거
        map[S[i].x][S[i].y]--;
    }

    //상어 갱신
    if(!S.empty()) S.erase(S.begin(), S.begin() + sSize);
}

void fightShark(int x, int y)
{

    // 가장 큰 상어의 크기를 기억한다.
    int biggest = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i].x == x && S[i].y == y)
        {
            biggest = max(biggest, S[i].size);
        }
    }

    // 가장 큰 상어를 제외하고 모두 제거
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i].x == x && S[i].y == y)
        {
            if(S[i].size != biggest) S.erase(S.begin() + i--);
        }
    }
    // 한 마리만 남게된다.
    map[x][y] = 1;
}

void SOLVE()
{
    int fisher = 1; // 낚시꾼이 위치한 행
    while(fisher <= c)
    {
        catchShark(fisher);

        moveShark();

        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                if(map[i][j] >= 2) fightShark(i,j);



        fisher++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}