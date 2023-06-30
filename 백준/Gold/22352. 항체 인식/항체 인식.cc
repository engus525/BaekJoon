#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m;
int before[31][31];
int after[31][31];
bool visited[31][31];
typedef pair<int, int> pii;
vector<pii> area[901];
int areaIdx = 0;
pii dir[4] = {{0,  -1},
              {0,  1},
              {-1, 0},
              {1,  0}};

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> before[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> after[i][j];
}

void BFS(int sx, int sy)
{
    queue<pii> q;
    q.emplace(sx,sy);

    while(!q.empty())
    {
        auto [x,y] = q.front();
        area[areaIdx].emplace_back(x,y);
        q.pop();

        for(auto & i : dir)
        {
            int nx = x + i.first;
            int ny = y + i.second;
            if(nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if(before[x][y] != before[nx][ny]) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.emplace(nx,ny);
        }
    }
}

void SOLVE()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(!visited[i][j])
                BFS(i,j),
                areaIdx++;

    int changed = 0;
    for(int i = 0; i < areaIdx; i++)
    {
        if (before[area[i][0].first][area[i][0].second]
        != after[area[i][0].first][area[i][0].second])
            changed++;

        set<int> cnt;
        for(auto &p : area[i])
            cnt.insert(after[p.first][p.second]);
        if(cnt.size() > 1)
        {
            cout << "NO";
            return;
        }
    }

    if(changed <= 1) cout << "YES";
    else cout << "NO";
}

int main()
{
    INPUT();
    SOLVE();
}