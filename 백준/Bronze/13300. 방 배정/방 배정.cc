#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,k,sex,y;
int map[7][2];

void INPUT()
{
    IAMFAST
    cin >> n >> k;
}

void SOLVE()
{
    while(n--)
    {
        cin >> sex >> y;
        map[y][sex]++;
    }

    int ans = 0;
    for(int i = 1; i <= 6; i++)
        for(int j = 0; j < 2; j++)
        {
            if(map[i][j] == 0) continue;
            else
            {
                if(map[i][j] % k) ans++;
                ans += map[i][j] / k;
            }
        }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}