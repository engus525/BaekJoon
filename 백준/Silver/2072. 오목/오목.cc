#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int board[20][20];

void INPUT()
{
    IAMFAST
    cin >> n;
}

bool isEnd(int x, int y)
{
    int count;

    // 가로
    count = 1;
    int nx = x, ny = y - 1;
    while (ny >= 1 && board[nx][ny] == board[x][y])
    {
        count++;
        ny--;
    }
    nx = x, ny = y + 1;
    while (ny <= 19 && board[nx][ny] == board[x][y])
    {
        count++;
        ny++;
    }

    if (count == 5) return true;
    // 세로
    count = 1;
    nx = x - 1, ny = y;
    while (nx >= 1 && board[nx][ny] == board[x][y])
    {
        count++;
        nx--;
    }
    nx = x + 1, ny = y;
    while (nx <= 19 && board[nx][ny] == board[x][y])
    {
        count++;
        nx++;
    }

    if (count == 5) return true;
    // 우하향
    count = 1;
    nx = x - 1, ny = y - 1;
    while (nx >= 1 && ny >= 1 && board[nx][ny] == board[x][y])
    {
        count++;
        nx--;
        ny--;
    }
    nx = x + 1, ny = y + 1;
    while (nx <= 19 && ny <= 19 && board[nx][ny] == board[x][y])
    {
        count++;
        nx++;
        ny++;
    }

    if (count == 5) return true;
    // 우상향
    count = 1;
    nx = x + 1, ny = y - 1;
    while (nx <= 19 && 1 <= ny && board[nx][ny] == board[x][y])
    {
        count++;
        nx++;
        ny--;
    }
    nx = x - 1, ny = y + 1;
    while (1 <= nx && ny <= 19 && board[nx][ny] == board[x][y])
    {
        count++;
        nx--;
        ny++;
    }

    if (count == 5) return true;
    return false;
}

void solution()
{
    int ans = -1;

    int turn = 1;
    int num = 1;
    while (num <= n)
    {
        int x, y;
        cin >> x >> y;

        board[x][y] = turn;
        if (isEnd(x, y))
        {
            ans = (ans == -1) ? num : min(ans, num);
        }

        if (turn == 1) turn = 2;
        else turn = 1;
        num++;
    }

    cout << ans;
}

int main()
{
    INPUT();
    solution();
}