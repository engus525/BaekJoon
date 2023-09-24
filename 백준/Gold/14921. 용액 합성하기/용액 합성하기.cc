#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int A[100001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
}

void solution()
{
    int ans = 2e9;
    int minGap = 2e9;

    int l = 0, r = n - 1;
    while (l < r)
    {
        int S = A[l] + A[r];

        if (minGap > abs(S)) ans = S, minGap = abs(S);

        if (S < 0) l++;
        else r--;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}