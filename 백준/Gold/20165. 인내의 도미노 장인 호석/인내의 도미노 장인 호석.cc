#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m, r;
int board[101][101];
bool dead[101][101];
pii dir[4] = {{0,  1},
              {0,  -1},
              {1,  0},
              {-1, 0}};

void INPUT()
{
    IAMFAST
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];
}

int getDir(char D)
{
    if (D == 'E') return 0;
    else if (D == 'W') return 1;
    else if (D == 'S') return 2;
    else if (D == 'N') return 3;
}

int collapse(int x, int y, int d)
{
    int score = 0;
    int collapseLen = board[x][y];
    if (d == 0)
    {
        for (int i = 0; i < collapseLen; i++)
            if (!dead[x][min(m, y + i)])
            {
                score++;
                dead[x][min(m, y + i)] = true;
                collapseLen = max(collapseLen, i + board[x][min(m, y + i)]);
            }
    }
    else if (d == 1)
    {
        for (int i = 0; i < collapseLen; i++)
            if (!dead[x][max(1, y - i)])
            {
                score++;
                dead[x][max(1, y - i)] = true;
                collapseLen = max(collapseLen, i + board[x][max(1, y - i)]);
            }
    }
    else if (d == 2)
    {
        for (int i = 0; i < collapseLen; i++)
            if (!dead[min(n, x + i)][y])
            {
                score++;
                dead[min(n, x + i)][y] = true;
                collapseLen = max(collapseLen, i + board[min(n, x + i)][y]);
            }
    }
    else if (d == 3)
    {
        for (int i = 0; i < collapseLen; i++)
            if (!dead[max(1, x - i)][y])
            {
                score++;
                dead[max(1, x - i)][y] = true;
                collapseLen = max(collapseLen, i + board[max(1, x - i)][y]);
            };
    }
    return score;
}

void solution()
{
    int ans = 0;

    for (int i = 0; i < 2 * r; i++)
    {
        int x, y, d;
        cin >> x >> y;

        if (i % 2 == 0)
        {
            char D;
            cin >> D;
            d = getDir(D);

            ans += collapse(x, y, d);
        } else dead[x][y] = false;

    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            (dead[i][j]) ? cout << "F " : cout << "S ";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}