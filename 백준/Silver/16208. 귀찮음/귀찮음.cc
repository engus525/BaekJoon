#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
ll len[500001];
ll sum = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++) cin >> len[i], sum += len[i];
}



void solution()
{
    sort(len, len + n, [](int a, int b){return a > b;});
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) ans += (sum - len[i]) * len[i], sum -= len[i];
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}