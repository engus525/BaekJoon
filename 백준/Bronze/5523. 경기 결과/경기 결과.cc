#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, a, b;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    while (n--)
    {
        int ai, bi; cin >> ai >> bi;
        if (ai > bi) a++;
        else if (ai < bi) b++;
    }
    cout << a << " " << b;
}

int main()
{
    INPUT();
    solution();
}