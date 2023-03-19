#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
pair<int,int> dir[4] = {{0,1},{-1,0},{0,-1},{1,0}};
struct CURVE
{
    int x,y,d,g;
};
vector<CURVE> v;
bool map[101][101];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x,y,d,g; cin>>x>>y>>d>>g;
        CURVE c = {y,x,d,g};
        v.emplace_back(c);
    }
}

void dragon(int idx)
{
    vector<int> li;
    li.emplace_back((v[idx].d+1)%4);
    map[v[idx].x][v[idx].y] = true;
    map[v[idx].x+dir[v[idx].d].first][v[idx].y+dir[v[idx].d].second] = true;

    int nx = v[idx].x+dir[v[idx].d].first;
    int ny = v[idx].y+dir[v[idx].d].second;

    for(int i = 0; i < v[idx].g; i++)
    {

        int cnt = pow(2,i);
        for(int j = 0; j < cnt; j++)
        {
            nx += dir[li[j]].first;
            ny += dir[li[j]].second;
            map[nx][ny] = true;

            li.emplace_back(li[j]);
            li[j] = (li[cnt-1-j]+1)%4;
        }
    }
}

void SOLVE()
{
    for(int i = 0; i < n; i++) dragon(i);

    int ans = 0;
    for(int i = 0; i <= 99; i++)
        for (int j = 0; j <= 99; j++)
            if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])
                ans++;
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}