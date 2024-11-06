#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
priority_queue<pii, vector<pii>, greater<>> pq;
int overtimeCnt;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.emplace(a - 1, b);
    }
}


void solution()
{
    int today = 0;
    while (!pq.empty())
    {
        auto [limit, need] = pq.top();
        pq.pop();

        while (need)
        {
            if (today > limit) break;
            if (today % 7 < 5) need--;
            today++;
        }

        overtimeCnt += need;
        if (overtimeCnt > limit + 1)
        {
            cout << -1;
            return;
        }
    }

    cout << overtimeCnt;
}

int main()
{
    INPUT();
    solution();
}