#include <iostream>
#include <stack>
using namespace std;

int n;
int h[80001];

typedef long long ll;//답의 최댓값 : 79999+79998+ ~~ + 0 = (79999*40000)
stack<pair<int,ll>> s;//{건물의 높이,볼 수 있는 옥상의 수}

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> h[i];
}


void SOLVE()
{
    ll ans = 0;
    for(int i = n-1; i >= 0; i--)
    {
        ll cnt = 0;
        while(!s.empty() && h[i] > s.top().first)
        {
            //{(현재 높이)에서 (볼 수 있는 옥상)에서 (볼 수 있는 옥상의 수)} + 1
            cnt += s.top().second + 1;
            //오른쪽 건물이 현재 건물에 count됨으로써 고려하지 않아도됨
            s.pop();
        }
        s.push({h[i],cnt});
        ans += cnt;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}