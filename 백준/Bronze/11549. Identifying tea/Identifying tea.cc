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
    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        int call; cin >> call;
        if (call == n) ans++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}