#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int t,n,l;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
}


void SOLVE()
{
    while(t--)
    {
        priority_queue<int> q;
        deque<int> wood;

        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> l;
            q.push(l);
        }
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0) wood.push_front(q.top());
            else wood.push_back(q.top());
            q.pop();
        }

        int ans = 0, front = wood.front();
        for(int i = 0; i < n - 1; i++)
        {
            int first = wood.front();
            wood.pop_front();
            int second = wood.front();

            ans = max(ans, abs(first - second));
        }
        // 가장 첫 통나무와 마지막 통나무 역시 인접해 있다.
        ans = max(ans, abs(front - wood.front()));

        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}
