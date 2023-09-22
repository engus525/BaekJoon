#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<int> v;

void INPUT()
{
    //IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int coding; cin >> coding;
        v.emplace_back(coding);
    }
}


void solution()
{
    //-6 -5 -4 -4 0 1 2 2 3 7
    sort(v.begin(), v.end());

    ll ans = 0;
    for (int cri = 0; n >= 3 && cri < v.size() - 2; cri++)
    {
        ll le = cri + 1, ri = ll(v.size()) - 1;
        while (le < ri)
        {
            int value = v[le] + v[ri] + v[cri];
            if (le == cri || value < 0) le++;
            else if (ri == cri || value > 0) ri--;
            else if (value == 0)
            {
                ll leq = 0, req = 0;
                ll leV = v[le], riV = v[ri];
                if (v[le] == v[ri])
                {
                    ans += (ri - le + 1) * (ri - le) / 2;
                    break;
                }
                while (v[le] == leV) leq++, le++;
                while (v[ri] == riV) req++, ri--;
                ans += leq * req;
            }
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}