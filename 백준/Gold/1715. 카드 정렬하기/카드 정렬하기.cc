#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> q;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int size; cin >> size;
        q.push(size);
    }
}

void SOLVE()
{
    int ans = 0;
    while (q.size())
    {
        if(q.size() == 1)
        {
            ans += 0;
            break;
        }

        int first = q.top(); q.pop();
        int second = q.top(); q.pop();

        ans += first + second;
        q.push(first + second);
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}