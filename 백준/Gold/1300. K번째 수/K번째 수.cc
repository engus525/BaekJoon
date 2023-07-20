#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

ll n,k;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
}


void solution()
{
    ll ans = 0;

    ll left = 1, right = n*n;
    while(left <= right)
    {
        ll mid = (left + right) / 2;

        ll cnt = 0;
        for(int i  = 1; i <= n; i++)
            cnt += min(n,mid/i);

        if(cnt < k) left = mid + 1;
        else ans = mid, right = mid - 1;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}