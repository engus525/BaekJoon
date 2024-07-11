#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
char board[101][101];
pii dir[8] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1},
};

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
            board[i][j] = str[j];
    }
}


void solution()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != 'M') continue;
            for (int k = 0; k < 8; k++)
            {
                bool mobis = false;
                for (int mov = 1; mov <= 4; mov++)
                {
                    int nx = i + dir[k].first * mov;
                    int ny = j + dir[k].second * mov;
                    if (nx < 0 || nx >= n) break;
                    if (ny < 0 || ny >= n) break;
                    if (mov == 1 && board[nx][ny] != 'O') break;
                    if (mov == 2 && board[nx][ny] != 'B') break;
                    if (mov == 3 && board[nx][ny] != 'I') break;
                    if (mov == 4 && board[nx][ny] != 'S') break;

                    if (mov == 4) mobis = true;
                }
                if (mobis) ans++;
            }
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}