#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void SOLVE()
{
    int ans = 0;
    while(n--)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int _ = 0; _ < 10; _++)
        {
            int a;
            cin >> a;
            pq.push(a);
            if (pq.size() > 3) pq.pop();
        }
        cout << pq.top() << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}