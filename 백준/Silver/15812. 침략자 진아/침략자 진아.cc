#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int city = 0, copyCity = 0;
char graph[21][21];
bool visited[21][21];
pii dir[4] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0}
};

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '1') city++;
            graph[i][j] = str[j];
        }
    }
    copyCity = city;
}

int bfs(int x1, int y1, int x2, int y2)
{
    queue<pii> q;
    q.emplace(x1, y1);
    q.emplace(x2, y2);
    visited[x1][y1] = true;
    visited[x2][y2] = true;

    int cnt = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            auto [a1, b1] = q.front();
            q.pop();

            if (graph[a1][b1] == '1') city--;
            if (city == 0) return cnt;


            for (auto &d: dir)
            {
                int na1 = a1 + d.first;
                int nb1 = b1 + d.second;

                if (na1 < 0 || na1 >= n || nb1 < 0 || nb1 >= m) continue;
                if (visited[na1][nb1]) continue;
//                cout << a1 << " " << b1 << " to " << na1 << " " << nb1 << '\n';
                q.emplace(na1, nb1);
                visited[na1][nb1] = true;
            }
        }
        cnt++;
    }

    return 2e9;
}

void solution()
{
    int ans = 2e9;
    for (int x1 = 0; x1 < n; x1++)
        for (int y1 = 0; y1 < m; y1++)
        {
            if (graph[x1][y1] == '1') continue;
            for (int x2 = x1; x2 < n; x2++)
                for (int y2 = 0; y2 < m; y2++)
                {
                    if (graph[x2][y2] == '1') continue;
                    if (x1 == x2 && y1 == y2) continue;
                    memset(visited, false, sizeof visited);
                    city = copyCity;
                    ans = min(ans, bfs(x1, y1, x2, y2));
                }
        }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}