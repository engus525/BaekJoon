#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
typedef long long ll;
ll li[5001];
ll _min = 4e9;
ll ans[3];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++) cin >> li[i];
}


void SOLVE()
{
    sort(li,li+n);

    for(int fix = 0; fix < n; fix++)
    {
        int left = fix+1;
        int right = n-1;
        while(left < right)
        {
            ll _sum = li[fix]+li[left]+li[right];

            if(abs(_min) > abs(_sum))
            {
                _min = _sum;
                ans[0] = li[fix];
                ans[1] = li[left];
                ans[2] = li[right];
            }

            if(_sum == 0) break;
            else if(_sum < 0) left++;
            else right--;
        }
    }

    for(int i = 0; i < 3; i++) cout << ans[i] << " ";
}

int main()
{
    INPUT();
    SOLVE();
}