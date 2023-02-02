#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n,k;
string name;

typedef long long ll;
queue<ll> q;//이름의 길이
ll cnt[21];
ll ans = 0;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
}


void SOLVE()
{
    while(n--)
    {
        cin >> name;
        q.push(name.length());

        if(q.size() > k+1)
        {
            cnt[q.front()]--;
            q.pop();
        }

        ans += cnt[name.length()];
        cnt[name.length()]++;
    }

    cout << ans;
}


int main()
{
    INPUT();
    SOLVE();
}