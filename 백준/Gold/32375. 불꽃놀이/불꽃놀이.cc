#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

int n, k;
deque<int> dq;
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (val >= k) ans++;
        else dq.emplace_back(val);
    }
}

void solution()
{
    sort(dq.begin(), dq.end());
    while (dq.size() >= 2)
    {
        if (dq[0] + dq[dq.size() - 1] < k)
        {
            dq.pop_front();
            continue;
        } else
        {
//            cout << dq.front() << " " << dq.back() << '\n';
            ans++, dq.pop_front(), dq.pop_back();
        }
    }
    cout << ((ans == 0) ? -1 : ans);
}

int main()
{
    INPUT();
    solution();
}