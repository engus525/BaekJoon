#include <iostream>
#include <cmath>
#include <queue>
#include <string>
#include <memory.h>
#include <map>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int n;
int board1[301][301], board2[301][301];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board1[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board2[i][j];
}



void solution()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int bit = 0;
            for (int k = 0; k < n; k++)
                bit = bit | (board1[i][k] & board2[k][j]);
            ans += bit;
        }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}