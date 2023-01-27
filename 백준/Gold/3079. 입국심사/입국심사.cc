#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n,m;
ll judge[100001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> judge[i];
}


void SOLVE()
{
    sort(judge,judge+n);

    ll left = 1;
    //모든 게이트가 한명씩 심사할 수 있는 시간 * {(사람수/게이트수) + 1}
    ll right = judge[n-1] * ((m/n)+1);

    ll ans;
    while(left <= right)
    {
        ll mid = (left+right) / 2;

        ll cnt = 0; //심사한 사람의 수
        for(int i = 0; i < n; i++) cnt += mid / judge[i];

        if(cnt >= m) ans = mid , right = mid - 1;
        else left = mid + 1;

    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}