#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll t, n;
ll rice[6];

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        cin >> n;
        ll Sum = 0;
        for (int i = 0; i < 6; i++) cin >> rice[i], Sum += rice[i];

        ll day = 1;
        while (Sum <= n) day++, Sum *= 4;
        cout << day << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}