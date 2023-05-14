#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int A[21][21];
int d1,d2;
int total = 0;
int area[21][21];
int ans = 2e9;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> A[i][j],
            total += A[i][j];
}

void Init()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            area[i][j] = false;
}

bool inRange(int x, int y)
{
    return (1<=x && x<=n && 1<=y && y<=n);
}

void checkArea(int x, int y)
{
    for(int i = x+1; i < x+d1+d2; i++)
        for(int j = 1; j <= n; j++)
        {
            if(area[i][j] != 5) continue;

            int idx = j+1;
            while(area[i][idx] != 5)
            {
                area[i][idx] = 5;
                idx++;
            }
            break;
        }

}

bool drawLine(int x, int y)
{//5번 선거구 경계선

    for(int i = 0; i <= d1; i++)
    {
        if(!inRange(x+i,y-i)) return false;
        else area[x+i][y-i] = 5;
    }
    for(int i = 0; i <= d2; i++)
    {
        if(!inRange(x+i,y+i)) return false;
        else area[x+i][y+i] = 5;
    }
    for(int i = 0; i <= d2; i++)
    {
        if(!inRange(x+d1+i,y-d1+i)) return false;
        else area[x+d1+i][y-d1+i] = 5;
    }
    for(int i = 0; i <= d1; i++)
    {
        if(!inRange(x+d2+i,y+d2-i)) return false;
        else area[x+d2+i][y+d2-i] = 5;
    }

    checkArea(x,y);
    return true;
}

void calcNum(int x, int y)
{
    //선거구별 인구 count
    int cnt[6] = {0};
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(area[i][j] == 5) continue;

            if(1<=i && i<x+d1 && 1<=j && j<=y) cnt[1] += A[i][j];
            else if(1<=i && i<=x+d2 && y<j && j<=n) cnt[2] += A[i][j];
            else if(x+d1<=i && i<=n && 1<=j && j<y-d1+d2) cnt[3] += A[i][j];
            else if(x+d2<i && i<=n && y-d1+d2<=j && j<=n) cnt[4] += A[i][j];
        }
    }
    cnt[5] = total-cnt[1]-cnt[2]-cnt[3]-cnt[4];

    //답 갱신
    int tempMax = -1, tempMin = 2e9;
    for(int i = 1; i <= 5; i++)
    {
        tempMax = max(tempMax,cnt[i]);
        tempMin = min(tempMin,cnt[i]);
    }
    ans = min(ans,tempMax-tempMin);
}

void Divide(int x, int y)
{
    for(d1 = 1; d1 <= n; d1++)
    {
        if(x+d1 > n) break;
        if(y-d1 < 1) break;
        for(d2 = 1; d2 <= n; d2++)
        {
            if(x+d2 > n) break;
            if(y+d2 > n) break;

            Init();
            if(!drawLine(x,y)) continue;

            calcNum(x,y);
        }
    }
}

void SOLVE()
{
    for(int i = 1; i <= n-2; i++)
        for(int j = 1; j <= n-1; j++)
        {
            Divide(i,j);
        }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}