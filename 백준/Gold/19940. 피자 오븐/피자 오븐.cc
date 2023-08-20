#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t, n;
int dir[5] = {60, 10, -10, 1, -1};
bool visited[61];

void INPUT()
{
    IAMFAST
    cin >> t;
}

void BFS(int target)
{
    queue<pair<int, vector<int>>> q;
    q.push({0, {n / 60, 0, 0, 0, 0}});
    visited[0] = true;

    while (!q.empty())
    {
        auto [now, v] = q.front();
        q.pop();

        if (now == target)
        {
            for(auto &i : v) cout << i << " ";
            cout << '\n';
            return;
        }

        for(int i = 5; i >= 0; i--)
        {
            int next = now + dir[i];
            if (next < 0 || next > 60) continue;
            if (visited[next]) continue;

            v[i]++;
            q.emplace(next, v);
            v[i]--;
        }
    }
}

void solution()
{
    while(t--)
    {
        cin >> n;
        memset(visited, false, sizeof visited);
        int target = n % 60;
        BFS(target);
    }
}

int main()
{
    INPUT();
    solution();
}