#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
ll n,m,k;
pair<ll,ll> beer[200001];
ll ans = -1;

void INPUT()
{
    IAMFAST
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++)
        cin >> beer[i].second >> beer[i].first;
}


void SOLVE()
{
    //sort asc by 도수레벨
    sort(beer+1,beer+1+k);

    ll left = 1, right = beer[k].first;
    while(left <= right)
    {
        ll mid = (left+right)/2;

        priority_queue<ll> pq;
        for(int i = 1; i <= k; i++)
        {
            if(mid < beer[i].first) break;
            else pq.push(beer[i].second);
        }

        if(pq.size() < n) left = mid + 1;
        else
        {
            ll prefer = 0;
            for(int _ = 0; _ < n; _++)
                prefer += pq.top(), pq.pop();

            if(prefer >= m) ans = mid, right = mid-1;
            else left = mid+1;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}