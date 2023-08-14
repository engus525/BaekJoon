#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;

void INPUT()
{
    IAMFAST
    cin >> t;
}


void solution()
{
    while(t--)
    {
        int ans = 0;

        int s; cin >> s; ans += s;
        int n; cin >> n;
        while(n--)
        {
            int a,b; cin >> a >> b;
            ans += a * b;
        }
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}