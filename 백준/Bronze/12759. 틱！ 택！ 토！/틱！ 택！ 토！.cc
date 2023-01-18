#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int first;
vector<pair<int,int>> v;
int map[4][4];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> first;

}

bool ttt()
{
    int cnt = 1;

    for(int i = 2; i <= 3; i++)
        if((map[i][i] == map[i-1][i-1]) && map[i][i]) cnt++;
    if(cnt == 3) return true;

    if((map[1][3] == map[2][2])
    && (map[2][2] == map[3][1])
    && map[1][3]) return true;

    for(int i = 1; i <= 3; i++)
    {
        cnt = 1;
        for(int j = 2; j <= 3; j++)
            if((map[i][j-1] == map[i][j]) && map[i][j]) cnt++;
        if(cnt == 3) return true;

        cnt = 1;
        for(int j = 2; j <= 3; j++)
            if((map[j-1][i] == map[j][i]) && map[j][i]) cnt++;
        if(cnt == 3) return true;
    }
    return false;
}

void SOLVE()
{
    for(int i = 0; i < 9; i++)
    {
        int x,y; cin >>x>>y;

        map[x][y] = first;

        if(ttt()) { cout << first; return;}
        else
        {
            if(first == 1) first = 2;
            else first = 1;
        }
    }
    cout << 0;
}

int main()
{
    INPUT();
    SOLVE();
}