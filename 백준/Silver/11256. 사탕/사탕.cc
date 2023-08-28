#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int t, n, m;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while(t--)
    {
        cin >> n >> m;
        priority_queue<int> pq;

        while(m--)
        {
            int r, c; cin >> r >> c;
            pq.emplace(r * c);
        }

        int ans = 0;
        while (n > 0)
        {
            ans++;
            n -= pq.top();
            pq.pop();
        }
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}