#include <iostream>
#include <algorithm>

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
    int ans = 10;

    int cri = 1;
    while (n >= cri * 2)
    {
        ans++;
        cri *= 2;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}