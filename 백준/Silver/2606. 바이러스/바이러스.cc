#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
int a,b;

vector<int> graph[101];
bool visited[101];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

int BFS()
{
    int ans = 0;

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];

            if(!visited[next])
            {
                ans++;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return ans;
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