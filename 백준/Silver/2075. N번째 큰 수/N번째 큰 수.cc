#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
int n;
priority_queue<ll,vector<ll>,greater<ll>> pq;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n*n; i++)
    {
        int num; cin >> num;
        pq.push(num);
        if(pq.size() > n) pq.pop();
    }
}


void SOLVE()
{
    cout << pq.top();
}

int main()
{
    INPUT();
    SOLVE();
}