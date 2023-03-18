#include <iostream>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int d,n,m;
int dist[50001];
int ans = 1;

void INPUT()
{
    IAMFAST
    cin >> d >> n >> m;
    for(int i = 0; i < n; i++) cin >> dist[i];
}


void SOLVE()
{
    sort(dist,dist+n);

    int left = 1, right = d;
    while(left <= right)
    {
        int mid = (left + right) / 2;

        int now = 0, cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(dist[i] < now + mid) continue;
            else cnt++, now = dist[i];
        }

        if(cnt >= n-m) ans = mid,left = mid+1;
        else right = mid-1;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}