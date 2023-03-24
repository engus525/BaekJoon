#include <iostream>
#include <algorithm>
using namespace std;

int m,n;
int map[701][701]; // 마지막에 1 더해서 출력
int gap[701][701];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
}

void growFirst(int x,int y,int z)
{
    // 왼쪽 열 아래에서 위로
    for(int i = m-1; i >= 0; i--)
    {
        if(x) map[i][0] += 0,gap[i][0] = 0,x--;
        else if(y) map[i][0] += 1,gap[i][0] = 1, y--;
        else map[i][0] += 2,gap[i][0] = 2, z--;
    }
    // 윗 열 왼쪽에서 오른쪽으로
    for(int i = 1; i < m; i++)
    {
        if(x) map[0][i] += 0,gap[0][i] = 0, x--;
        else if(y) map[0][i] += 1,gap[0][i] = 1, y--;
        else map[0][i] += 2,gap[0][i] = 2, z--;
    }
}

int growthSize(int x, int y)
{// L D U 중 가장 많이 자란 애벌레가 자란 정도를 반환
    return max(gap[x][y-1],max(gap[x-1][y],gap[x-1][y-1]));
}

void growElse()
{
    for(int i = 1; i < m; i++)
        for(int j = 1; j < m; j++)
        {
            int gS = growthSize(i,j);
            map[i][j] += gS;
            gap[i][j] = gS;
        }
}

void SOLVE()
{
    while(n--)
    {
        int a,b,c; cin >> a >> b >> c;
        growFirst(a,b,c);
        growElse();
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
            cout << map[i][j] + 1 << " ";
        cout << '\n';
    }

}

int main()
{
    INPUT();
    SOLVE();
}