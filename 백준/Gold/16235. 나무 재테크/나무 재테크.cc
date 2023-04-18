#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m,t;
int A[101][101];
int food[101][101];//양분
int addFood[101][101];//여름에 추가될 양분
typedef pair<int,int> pii;
pii dir[8] = {{-1,0},
              {-1,1},
              {0,1},
              {1,1},
              {1,0},
              {1,-1},
              {0,-1},
              {-1,-1}
              };
deque<int> tree[101][101];
int addTreeCnt[101][101];
int x,y,z;

int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> A[i][j],
            food[i][j] = 5-A[i][j];

    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        tree[x][y].push_front(z);
        ans++;
    }
}

void Spring()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            //Winter 최적화
            food[i][j] += A[i][j];

            int k = 0;
            for(; k < tree[i][j].size(); k++)
            {
                if(tree[i][j][k] > food[i][j]) break;
                food[i][j] -= tree[i][j][k];
                tree[i][j][k]++;
            }

            //Summer 최적화
            for(int x = tree[i][j].size()-1; x >= k; x--)
            {
                food[i][j] += tree[i][j][x]/2;
                tree[i][j].pop_back();
                ans--;
            }
        }
}

void Fall()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            for(int k = 0; k < tree[i][j].size(); k++)
            {
                //번식할 수 있는 나무라면
                if(tree[i][j][k]%5 == 0)
                {
                    for(auto [a,b] : dir)
                    {
                        a += i; b += j;
                        if(a<1 || n<a || b<1 || n<b) continue;
                        addTreeCnt[a][b]++;
                        ans++;
                    }
                }
            }

        }


    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < addTreeCnt[i][j]; k++)
                tree[i][j].push_front(1);
            addTreeCnt[i][j] = 0;
        }
}


void SOLVE()
{
    while(t--)
    {
        Spring();//+Winter,Summer
        Fall();
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}