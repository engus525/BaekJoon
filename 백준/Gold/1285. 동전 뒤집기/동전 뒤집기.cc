#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
char map[21][21];
int ans = 0,first = 0;

void INPUT()
{
    //IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int  j = 0; j < n; j++)
        {
            scanf("%1s", &map[i][j]);
            if(map[i][j] == 'T') ans++;
        }
}

void Reverse(int k)
{
    for(int i = 0; i < n; i++)
        map[k][i] = (map[k][i] == 'H') ? 'T' : 'H';
}

void setAns()
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int colCnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(map[j][i] == 'H')
                colCnt++;
        }
        cnt += min(colCnt,n-colCnt);
    }
    ans = min(ans,cnt);
}

void DFS(int row)
{
    if(row == n)
    {
        setAns();
        return;
    }

    for(int i = row; i < n; i++)
    {
        Reverse(i);
        DFS(i+1);
        Reverse(i);//backtracking
    }
}

void SOLVE()
{
    DFS(0);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}