#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int A[501][501];
double pattern[4][5][5] = {{{0, 0, 2, 0, 0},
                                   {0, 10, 7, 1, 0},
                                   {5, 0, 0, 0, 0},
                                   {0, 10, 7, 1, 0},
                                   {0, 0, 2, 0, 0}},
                           {{0, 0, 0, 0, 0},
                                   {0, 1, 0, 1, 0},
                                   {2, 7, 0, 7, 2},
                                   {0, 10, 0, 10, 0},
                                   {0, 0, 5, 0, 0}},
                           {{0, 0, 2, 0, 0},
                                   {0, 1, 7, 10, 0},
                                   {0, 0, 0, 0, 5},
                                   {0, 1, 7, 10, 0},
                                   {0, 0, 2, 0, 0}},
                           {{0, 0, 5, 0, 0},
                                   {0, 10, 0, 10, 0},
                                   {2, 7, 0, 7, 2},
                                   {0, 1, 0, 1, 0},
                                   {0, 0, 0, 0, 0}},};

typedef pair<int, int> pii;
pii pos[5][5];
pii dir[4] = {{0,  -1},
              {1,  0},
              {0,  1},
              {-1, 0}};
pii shark;
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> A[i][j];
    shark = {(n / 2) + 1, (n / 2) + 1};
}

void setBase()
{
    //setPos
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            pos[i][j].first = -2 + i,
                    pos[j][i].second = -2 + i;

    //setPattern
//    for (int d = 0; d < 3; d++)
//    {
//        for (int i = 0; i < n; i++)
//            for (int j = n - 1; j >= 0; j--)
//                pattern[d + 1][n - 1 - j][i] = pattern[d][i][j];
//    }
}

void Spread(int x, int y, int d)
{
    int movedSand = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            auto [a, b] = pos[i][j];
            int nx = x + a;
            int ny = y + b;
            if (pattern[d][i][j] == 0) continue;//0%


            int sand = A[x][y] * (pattern[d][i][j] / 100);
            movedSand += sand;
            //모래가 격자 밖으로 나가는 경우
            if (nx < 1 || n < nx || ny < 1 || n < ny)
            {
                ans += sand;
                continue;
            }
            A[nx][ny] += sand;

        }
    }

    int leftSand = A[x][y] - movedSand;
    if (x + dir[d].first < 1 || n < x + dir[d].first ||
        y + dir[d].second < 1 || n < y + dir[d].second)
        ans += leftSand;
    else A[x + dir[d].first][y + dir[d].second] += leftSand;
    A[x][y] = 0;
}

void Print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << A[i][j] << " ";
        cout << '\n';
    }
}

void SOLVE()
{
    setBase();

    int d = 0;
    for (int moveCnt = 1;; moveCnt++)
    {
        for (int twice = 0; twice < 2; twice++)
        {
            for (int cnt = 0; cnt < moveCnt; cnt++)
            {
                auto [x, y] = shark;
                shark = {x + dir[d].first, y + dir[d].second};

                if (A[shark.first][shark.second])
                    Spread(shark.first, shark.second, d);
                if (x == 1 && y == 1)
                {
                    cout << ans;
                    return;
                }
            }
            d = (d + 1) % 4;
        }
    }
}

int main()
{
    INPUT();
    SOLVE();
}