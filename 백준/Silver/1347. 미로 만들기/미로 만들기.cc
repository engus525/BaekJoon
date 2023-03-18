#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
string str;
bool map[105][105];
typedef pair<int,int> pii;
pii dir[4] = {{1,0},{0,-1},{-1,0},{0,1}};

void INPUT()
{
    IAMFAST
    cin >> n >> str;
}

void SOLVE()
{
    //지도 범위
    int sx = 50,sy = 50, ex = 50, ey = 50;
    //현재 위치와 방향
    int x = 50, y = 50, news = 0;
    map[x][y] = true;

    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'L')
            news = (news == 0) ? 3 : news-1;
        else if(str[i] == 'R') news = (news+1)%4;
        else
        {
            x = x + dir[news].first;
            y = y + dir[news].second;
            map[x][y] = true;//이동할 수 있는 칸 표시
        }

        //지도 범위 갱신
        sx = min(sx,x); sy = min(sy,y);
        ex = max(ex,x); ey = max(ey,y);
    }

    for(int i = sx; i <= ex; i++)
    {
        for (int j = sy; j <= ey; j++)
        {
            if (map[i][j]) cout << '.';
            else cout << '#';
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}