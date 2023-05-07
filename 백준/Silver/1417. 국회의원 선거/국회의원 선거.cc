#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, cri;
priority_queue<int> pq;
int x;

void INPUT()
{
    IAMFAST
    cin >> n >> cri; n--;
    while(n--) cin >> x, pq.push(x);
}


void SOLVE()
{
    int ans = 0;
    while(pq.size() && cri <= pq.top())
    {
        ans++;
        cri++;
        pq.push(pq.top()-1);
        pq.pop();
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}