#include <iostream>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    int ans = 1;
    for (int i = 0; i < (n+1)/2; i++) ans *= 2, ans %= 16769023;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}