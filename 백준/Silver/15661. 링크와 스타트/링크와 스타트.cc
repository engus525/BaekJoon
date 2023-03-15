#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int map[21][21];
int ans = 2e9;
bool visited[21];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> map[i][j];
}

void setAns()
{
    int start = 0;
    int link = 0;
    for(int i = 1; i <= n-1; i++)
        for(int j = i+1; j <= n; j++)
        {
            if (visited[i] && visited[j])
                start += map[i][j] + map[j][i];
            else if (!visited[i] && !visited[j])
                link += map[i][j] + map[j][i];
        }

    ans = min(ans,abs(start-link));
}

void setPerm(int cnt,int start)
{
    if(cnt > n/2) return;
    if(cnt > 0) setAns();

    for(int i = start; i <= n; i++)
    {
        visited[i] = true;
        setPerm(cnt + 1,i+1);
        visited[i] = false;
    }
}

void SOLVE()
{
    setPerm(0,1);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}