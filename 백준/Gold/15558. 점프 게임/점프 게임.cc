#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,k;
int map[2][100001];
bool visited[2][100001];
typedef pair<int,int> pii;

void INPUT()
{
    //IAMFAST
    cin >> n >> k;
    for(int i = 0; i < 2; i++)
        for(int j = 1; j <= n; j++)
            scanf("%1d",&map[i][j]);
}

bool BFS()
{
    int dangerLine = 0;
    queue<pii> q;
    q.push({0,1});

    while(!q.empty())
    {
        int qSize = q.size();

        while(qSize--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (y > n) return true;

            if (visited[x][y]) continue;
            if (dangerLine == y) continue;
            if (map[x][y] == 0) continue;
            visited[x][y] = true;

            q.push({x, y + 1});
            q.push({x, y - 1});
            q.push({1 - x, y + k});
        }
        dangerLine++;
    }
    return false;
}

void SOLVE()
{
    cout << BFS();
}

int main()
{
    INPUT();
    SOLVE();
}