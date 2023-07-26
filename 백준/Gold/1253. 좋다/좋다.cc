#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

int n;
vector<ll> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll num; cin >> num;
        v.emplace_back(num);
    }
}


void solution()
{
    sort(v.begin(), v.end());

    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll target = v[i];

        int left = 0, right = n - 1;
        while(left < right)
        {
            ll now = v[left] + v[right];

            if (now == target)
            {
                if (i == left) left++;
                else if (i == right) right--;
                else
                {
                    ans++;
                    break;
                }
            }
            else if (now < target) left++;
            else right--;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}