#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, m, k;
struct Fire
{
    int r, c, m, s, d;
};
vector<Fire> map[51][51];
vector<Fire> ball;
pair<int,int> dir[8] = {{-1, 0},
              {-1, 1},
              {0,  1},
              {1,  1},
              {1,  0},
              {1,  -1},
              {0,  -1},
              {-1, -1}};

void INPUT()
{
    IAMFAST
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        Fire fire;
        cin >> fire.r >> fire.c >> fire.m >> fire.s >> fire.d;
        ball.push_back(fire);
        map[fire.r][fire.c].push_back(fire);
    }
}

int setPos(int p)
{
    if (p > n) return p - n;
    else if (p < 1) return p + n;
    else return p;
}

void Move()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            map[i][j].clear();

    for (auto &f : ball)
    {
        int nx = setPos(f.r + dir[f.d].first * (f.s%n));
        int ny = setPos(f.c + dir[f.d].second * (f.s%n));

        map[nx][ny].push_back({nx, ny, f.m, f.s, f.d});
        f.r = nx;
        f.c = ny;
    }

}

bool evenDir(vector<int> &v)
{
    bool allOdd = true, allEven = true;
    for (auto i: v)
    {
        if (i % 2) allOdd = false;
        else allEven = false;
    }
    return (allOdd || allEven);
}

void SumAndDivide()
{
    vector<Fire> newBall;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j].empty()) continue;
            if (map[i][j].size() == 1)
            {
                newBall.push_back(map[i][j][0]);
                continue;
            }

            //==========SUM
            int mSum = 0;
            int sSum = 0;
            vector<int> dirs;
            for (int idx = 0; idx < map[i][j].size(); idx++)
            {
                Fire now = map[i][j][idx];

                mSum += now.m;
                sSum += now.s;
                dirs.emplace_back(now.d);
            }

            //==========DIVIDE
            if (mSum / 5 == 0) continue;
            else
            {
                int d = (evenDir(dirs)) ? 0 : 1;
                for (; d <= 7; d += 2)
                    newBall.push_back({i, j, mSum / 5, sSum / int(map[i][j].size()), d});
            }

        }
    }
    ball = newBall;
}

int getAns()
{
    int ans = 0;
    for (auto f: ball) ans += f.m;
    return ans;
}

void SOLVE()
{
    while (k--)
    {
        Move();
        SumAndDivide();
    }

    cout << getAns();
}

int main()
{
    INPUT();
    SOLVE();
}