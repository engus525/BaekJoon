#include <iostream>
#include <algorithm>
using namespace std;

int map[10][10];
int ans = -1, x, y;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
        {
            cin >> map[i][j];
            if(ans < map[i][j])
            {
                ans = map[i][j];
                x = i;
                y = j;
            }
        }
}


void SOLVE()
{
    cout << ans << '\n' << x << " " << y;
}

int main()
{
    INPUT();
    SOLVE();
}
