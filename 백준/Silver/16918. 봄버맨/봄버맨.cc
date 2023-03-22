#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int r,c,n;
char map[201][201];
typedef pair<int,int> pii;
vector<pii> v;
pii dir[4] = {{0,1},
              {0,-1},
              {-1,0},
              {1,0}};

void INPUT()
{
    //IAMFAST
    cin >> r >> c >> n;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%1s", &map[i][j]);
}

void fillBomb()
{
    v.clear();
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            if(map[i][j] == 'O') v.emplace_back(i,j);
            else map[i][j] = 'O';
        }
}

void Boom()
{
    for(auto [x,y] : v)
    {
        map[x][y] = '.';
        for(int d = 0; d < 4; d++)
        {
            int nx = x + dir[d].first;
            int ny = y + dir[d].second;
            if(!(0<=nx&&nx<r&&0<=ny&&ny<c)) continue;

            map[nx][ny] = '.';
        }
    }
}

void SOLVE()
{
    for(int i = 2; i <= n; i++)
    {
        if(i%2 == 0) fillBomb();
        else Boom();
    }

    for(int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}