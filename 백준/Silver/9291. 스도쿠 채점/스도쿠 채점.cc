#include <iostream>
#include <queue>
#include <set>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int board[10][10];

void INPUT()
{
    IAMFAST
    cin >> n;
}

bool checkRow()
{
    bool row = true;
    for (int i = 0; i < 9; i++)
    {
        set<int> S;
        for (int j = 0; j < 9; j++) S.emplace(board[i][j]);

        if (S.size() != 9) row = false;
    }
    return row;
}

bool checkCol()
{
    bool col = true;
    for (int i = 0; i < 9; i++)
    {
        set<int> S;
        for (int j = 0; j < 9; j++) S.emplace(board[j][i]);

        if (S.size() != 9) col = false;
    }
    return col;
}

bool checkRect()
{
    bool rect = true;
    for (int i = 0; i < 9; i++)
    {
        if (i % 3) continue;
        for (int j = 0; j < 9; j++)
        {
            if (j % 3) continue;
            set<int> S;
            for (int x = i; x < i + 3; x++)
                for (int y = j; y < j + 3; y++)
                    S.emplace(board[x][y]);

            if (S.size() != 9) rect = false;
        }

    }
    return rect;
}

void solution()
{
    for (int cnt = 1; cnt <= n; cnt++)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> board[i][j];

        bool row = checkRow();
        bool col = checkCol();
        bool rect = checkRect();

        cout << "Case " << cnt << ": ";
        cout << ((row && col && rect) ? "CORRECT" : "INCORRECT") << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}