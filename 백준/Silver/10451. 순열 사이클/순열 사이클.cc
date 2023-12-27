#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
int graph[1001];

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        int n;
        cin >> n;

        bool visited[1001];
        memset(visited, false, sizeof visited);

        for (int i = 1; i <= n; i++) cin >> graph[i];

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i]) continue;

            ans++;

            int now = i;
            visited[now] = true;
            while (!visited[graph[now]])
            {
                now = graph[now];
                visited[now] = true;
            }
        }

        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}