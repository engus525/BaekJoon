#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,l;

int a;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> pq;// {value,index}

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l;
}


void SOLVE()
{
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        pq.push({a,i});

        while(!(max(0,i-l+1) <= pq.top().second
        && pq.top().second <= i)) pq.pop();

        cout << pq.top().first << " ";
    }
}

int main()
{
    INPUT();
    SOLVE();
}