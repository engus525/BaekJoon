#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,k;
priority_queue<int> pq;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        pq.push(x);
    }
}

void SOLVE()
{
    for(int i = 0; i < k-1; i++) pq.pop();
    cout << pq.top();
}

int main()
{
    INPUT();
    SOLVE();
}