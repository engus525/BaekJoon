#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int val[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> val[i];
}


void solution()
{
    sort(val, val + n);
    //3 3 5 5 6 7

    int ans = 0;

    int l = 0, r = n - 1;
    while (l < r)
    {
        int total = val[l] + val[r];

        if (total >= m) ans++, l++, r--;
        else l++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}