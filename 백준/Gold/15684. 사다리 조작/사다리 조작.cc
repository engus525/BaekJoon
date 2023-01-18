#include <iostream>
using namespace std;

int n,m,h;
int ladder[31][11];

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        ladder[a][b] = 1;
    }
}

bool n_to_n()
{
    for(int i = 1; i <= n; i++)
    {
        int x = 1, y = i;
        while(x <= h)
        {
            // 연결된 가로선이 있다면 이동
            if(ladder[x][y] == 1) y++;
            else if(ladder[x][y - 1] == 1) y--;

            // 아래로 이동
            x++;
        }
        //cout << i << " to " << y << '\n';
        if(i != y) return false;
    }
    return true;
}



bool DFS(int cnt, int limit)
{

    if(cnt == limit)
    {
        if(n_to_n()) return true;
        else return false;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= h; j++)
        {
            // 사다리를 설치할 수 없으면 continue
            if(ladder[j][i] || ladder[j][i - 1] || ladder[j][i + 1])
                continue;

            ladder[j][i] = 1;
            if(DFS(cnt + 1, limit)) return true;
            ladder[j][i] = 0;

            while(!ladder[j][i-1] && !ladder[j][i+1]) j++;
        }
    }
    return false;
}

void SOLVE()
{

    int ans = 0;
    while(ans <= 3)
    {
        if(DFS(0, ans)) break;
        ans++;
    }
    if(ans <= 3) cout << ans;
    else cout << -1;
}

int main()
{
    INPUT();
    SOLVE();
}
