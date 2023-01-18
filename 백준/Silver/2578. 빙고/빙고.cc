#include <iostream>
#include <vector>
using namespace std;

int map[5][5];
bool visited[5][5];
vector<pair<int,int>> pos[26];

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
        {
            cin >> map[i][j];
            pos[map[i][j]].push_back({i,j});
        }


}

int bingoCnt()
{
    int bc = 0;

    int d1 = 0, d2 = 0; // 우하향 대각선, 좌하향 대각선
    for(int i = 0; i < 5; i++)
    {
        int r = 0, c = 0, d = 0;

        // 우하향 대각선
        if(visited[i][i]) d1++;
        // 좌하향 대각선
        if(visited[i][4 - i]) d2++;

        // 행과 열
        for (int j = 0; j < 5; j++)
        {
            if(visited[i][j]) r++; // 행
            if(visited[j][i]) c++; // 열
        }

        if(r == 5) bc++;
        if(c == 5) bc++;
        if(d1 == 5) bc++;
        if(d2 == 5) bc++;
    }

    return bc;
}


void SOLVE()
{
    int ans = 0;
    for(int i = 0; i < 25; i++)
    {
        int num; cin >> num;

        visited[pos[num][0].first][pos[num][0].second] = true;
        if(bingoCnt() >= 3)
        {
            ans = i + 1;
            break;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
