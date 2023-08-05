#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

long double n,l,w,h;

void INPUT()
{
    IAMFAST
    cin >> n >> l >> w >> h;
}


void solution()
{
    long double ans = 0;
    long double left = 1, right = 1'000'000'000;
    for (int i = 0; i < 1000; i++)
    {
        long double mid = (left + right) / 2;

        long double count = (ll(l/mid) * ll(w/mid) * ll(h/mid));

        if (count >= n) left = mid + 1, ans = mid;
        else right = mid - 1;
    }
    cout << fixed; cout.precision(15);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}