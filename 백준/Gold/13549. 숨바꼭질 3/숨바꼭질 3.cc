#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

int n, k;
int visited[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> k;
}

int BFS()
{
    deque<int> q;
    q.emplace_back(n);
    visited[n] = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop_front();

        if (now == k) return visited[now];

        if (2 * now <= 100000 && visited[2 * now] > visited[now])
            visited[2 * now] = visited[now],
                    q.emplace_back(2 * now);
        if (now + 1 <= 100000 && visited[now + 1] > visited[now] + 1)
            visited[now + 1] = visited[now] + 1,
                    q.emplace_back(now + 1);
        if (now - 1 >= 0 && visited[now - 1] > visited[now] + 1)
            visited[now - 1] = visited[now] + 1,
                    q.emplace_back(now - 1);
    }

    return 0;
}

void solution()
{
    for(int i = 0; i < 100001; i++) visited[i] = 2e9;
    cout << BFS();
}

int main()
{
    INPUT();
    solution();
}