#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int r,c;
char map[501][501];
typedef pair<int,int> pii;
pii dir[4] = {{0,1},
              {0,-1},
              {1,0},
              {-1,0}};


void INPUT()
{
    //IAMFAST
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%1s",&map[i][j]);
}

bool stickW(int x,int y)
{
    for(auto [a,b] : dir)
    {
        int nx = x + a;
        int ny = y + b;
        if(nx < 0 || r <= nx || ny < 0 || c <= ny) continue;
        if(map[nx][ny] == 'W') continue;
        if(map[nx][ny] == 'S') return false;
        map[nx][ny] = 'D';
    }
    return true;
}

void SOLVE()
{
    bool ans = true;
    for(int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == 'W')
                if (!stickW(i, j))
                    ans = false;

            if (!ans) break;
        }
        if(!ans) break;
    }

    cout << ans << '\n';
    if(ans)
    {
        for(int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << map[i][j];
            cout << '\n';
        }
    }
}

int main()
{
    INPUT();
    SOLVE();
}