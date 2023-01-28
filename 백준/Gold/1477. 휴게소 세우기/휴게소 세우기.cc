#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,l;
vector<int> v;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> l;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }
}


void SOLVE()
{
    v.push_back(0); v.push_back(l);
    sort(v.begin(),v.end());

    int left = 1 , right = l;

    int ans;
    while(left <= right)
    {
        int mid = (left + right) / 2;

        int cnt = 0;//설치한 휴게소 갯수
        for(int i = 1; i <= n+1; i++)
        {
            int dist = v[i] - v[i-1];

            cnt += dist / mid;
            if(dist % mid == 0) cnt--;
        }

        if(cnt <= m) ans = mid , right = mid - 1;
        else left = mid + 1;
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}