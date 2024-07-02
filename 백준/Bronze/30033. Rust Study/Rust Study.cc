#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int a[1001], b[1001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
}


void solution()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (a[i] <= b[i]) ans++;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}