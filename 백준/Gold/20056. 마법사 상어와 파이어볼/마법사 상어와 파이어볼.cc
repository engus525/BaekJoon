#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m,k;
struct Fire
{
    int r,c,m,s,d;
};
vector<Fire> map[51][51];
vector<Fire> ball;
typedef pair<int,int> pii;
pii dir[8] = {{-1,0},
              {-1,1},
              {0,1},
              {1,1},
              {1,0},
              {1,-1},
              {0,-1},
              {-1,-1}};

void INPUT()
{
    IAMFAST
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        Fire fire;
        cin>>fire.r>>fire.c>>fire.m>>fire.s>>fire.d;
        ball.push_back(fire);
        map[fire.r][fire.c].push_back(fire);
    }
}

void Move()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            map[i][j].clear();

    for(int i = 0; i < ball.size(); i++)
    {
        Fire now = ball[i];

        int nx = now.r+dir[now.d].first*now.s;
        if(nx > 0)
        {
            if (nx % n == 0) nx = n;
            else nx %= n;
        }
        else nx = n - abs(now.r+dir[now.d].first*now.s)%n;

        int ny = now.c+dir[now.d].second*now.s;
        if(ny > 0)
        {
            if (ny % n == 0) ny = n;
            else ny %= n;
        }
        else ny = n - abs(now.c+dir[now.d].second*now.s)%n;

        map[nx][ny].push_back({nx,ny,now.m,now.s,now.d});
        ball[i].r = nx;
        ball[i].c = ny;
    }

}

bool evenDir(vector<int> &v)
{
    bool allOdd = true, allEven = true;
    for(auto i : v)
    {
        if(i%2) allOdd = false;
        else allEven = false;
    }
    return (allOdd || allEven);
}

void SumAndDivide()
{
    vector<Fire> newBall;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(map[i][j].empty()) continue;
            if(map[i][j].size() == 1)
            {
                newBall.push_back(map[i][j][0]);
                continue;
            }

            //==========SUM
            int mSum = 0;
            int sSum = 0;
            int cnt = map[i][j].size();
            vector<int> dirs;
            for(int idx = 0; idx < map[i][j].size(); idx++)
            {
                Fire now = map[i][j][idx];

                mSum += now.m;
                sSum += now.s;
                dirs.emplace_back(now.d);
            }

            //==========DIVIDE
            if(mSum/5 == 0) continue;
            else
            {
                if(evenDir(dirs))
                    for(int d = 0; d <= 6; d+=2)
                        newBall.push_back({i,j,mSum/5,sSum/cnt,d});
                else
                    for(int d = 1; d <= 7; d+=2)
                        newBall.push_back({i,j,mSum/5,sSum/cnt,d});
            }

        }
    }
    ball = newBall;
}

int getAns()
{
    int ans = 0;
    for(auto f : ball) ans += f.m;
    return ans;
}

void SOLVE()
{
    while(k--)
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