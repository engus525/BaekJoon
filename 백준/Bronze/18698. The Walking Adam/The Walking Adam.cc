#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
string str;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    while (n--)
    {
        cin >> str;
        int ans = 0;
        for (auto s : str)
        {
            if (s == 'U') ans++;
            else break;
        }
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}