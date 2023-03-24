#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int h,w;
char map[101][101];
int visited[101][101];

void INPUT()
{
    //IAMFAST
    cin >> h >> w;
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
        {
            visited[i][j] = -1;
            scanf("%1s", &map[i][j]);
            if(map[i][j] == 'c')
                visited[i][j] = 0;
        }
}

bool Move(int cnt)
{
    int moved = false;
    for(int i = 1; i<= h; i++)
        for(int j = w; j >= 1; j--)
            if(map[i][j] == 'c')
            {
                moved = true;
                if(j == w) map[i][j] = '.';
                else
                {
                    map[i][j+1] = 'c';
                    map[i][j] = '.';
                    if(visited[i][j+1] == -1) visited[i][j+1] = cnt;
                }
            }
    return moved;
}

void SOLVE()
{
    int cnt = 0;
    while(++cnt)
    {
        if(!Move(cnt)) break;
    }

    for(int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
            cout << visited[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}