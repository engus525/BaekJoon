#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
int map[1001];
int visited[1001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> map[i];
}

void BFS()
{
    queue<int> q;
    q.emplace(1);
    visited[1] = 0;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(int i = 1; i <= map[now]; i++)
        {
            int next = now + i;
            if(next > n) continue;
            if(visited[next] != -1) continue;

            visited[next] = visited[now] + 1;
            q.emplace(next);
        }
    }
}

void solution()
{
    memset(visited,-1,sizeof visited);
    BFS();
    cout << visited[n];
}

int main()
{
    INPUT();
    solution();
}