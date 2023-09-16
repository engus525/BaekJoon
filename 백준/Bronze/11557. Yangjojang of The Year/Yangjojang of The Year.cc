#include <iostream>
#include <algorithm>

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
    while (t--)
    {
        string str; int n, val;
        cin >> n;
        int max_val = 0;
        string ans;

        while (n--)
        {
            cin >> str >> val;
            
            if (max_val < val)
            {
                max_val = max(val, max_val);
                ans = str;
            }
        }
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}