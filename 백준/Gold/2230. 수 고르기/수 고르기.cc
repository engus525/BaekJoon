#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int A[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> A[i];
}


void solution()
{
    sort(A, A + n);

    int ans = 2e9;

    int l = 0, r = 1;
    while (r < n)
    {
        int gap = A[r] - A[l];

        if (gap < m) r++;
        else
        {
            ans = min(ans, gap);
            l++;
            if (l == r) r++;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}