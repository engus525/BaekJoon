#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, target, m;
bool obs[1001];

void INPUT()
{
    IAMFAST
    cin >> n >> target >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        obs[num] = true;
    }
}

void solution()
{
    int ans = 1;
    while (true)
    {
//        cout << "ans : " << ans << '\n';
        int now = 1;
        bool visited[1001];
        memset(visited, false, sizeof visited);
        visited[1] = true;
        while (true)
        {
            int next = (now + ans) % n;
            if (next == 0) next = n;

            if (obs[next]) break;
            if (visited[next]) break;
//            cout << now << " to " << next << '\n';
            now = next;
            visited[next] = true;
            if (visited[target]) break;
        }
        if (visited[target]) break;
        ans++;
    }
    cout << ans;
}


int main()
{
    INPUT();
    solution();
}