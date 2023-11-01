#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int a, b;
vector<int> graph[51];
int visited[51];
int score[51];

void INPUT()
{
    IAMFAST
    cin >> n;
    while (cin >> a >> b)
    {
        if (a == -1) break;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
}

int BFS(int x)
{
    int dist = 0;

    queue<int> q;
    q.emplace(x);
    visited[x] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (visited[next]) continue;

            visited[next] = visited[now] + 1;
            dist = max(dist, visited[next] - 1);
            q.emplace(next);
        }
    }
    return dist;
}

void solution()
{
    int candiScore = 2e9;
    int candiNum = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof visited);
        score[i] = BFS(i);
        candiScore = min(candiScore, score[i]);
    }

    for (int i = 1; i <= n; i++)
        if (score[i] == candiScore) candiNum++;

    cout << candiScore << " " << candiNum << '\n';
    for (int i = 1; i <= n; i++)
        if (score[i] == candiScore)
            cout << i << " ";

}

int main()
{
    INPUT();
    solution();
}