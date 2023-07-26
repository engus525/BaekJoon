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
//        cout << "target : " << target << '\n';

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
//                    cout << v[left] << " + " << v[right] << '\n';
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