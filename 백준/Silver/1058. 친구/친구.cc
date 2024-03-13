#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<int> graph[51];
bool visited[51];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < n; j++)
        {
            if (str[j] == 'Y')
            {
                graph[i].emplace_back(j);
                graph[j].emplace_back(i);
            }
        }
    }
}

int BFS(int start)
{
    int cnt = 0;

    queue<int> q;
    memset(visited, false, sizeof visited);
    visited[start] = true;
    for (auto s : graph[start])
        if (!visited[s]) q.emplace(s), cnt++, visited[s] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (auto next : graph[now])
        {
            if (visited[next]) continue;

            visited[next] = true;
            cnt++;
        }

    }
    return cnt;
}

void solution()
{
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(BFS(i), ans);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}