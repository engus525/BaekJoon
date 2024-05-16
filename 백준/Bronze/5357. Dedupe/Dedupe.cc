#include <iostream>
#include <math.h>
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
    while (n--)
    {
        string str;
        cin >> str;

        string ans;
        for (int i = 0; i < str.length(); i++)
            if (!i || (i && str[i - 1] != str[i]))
                ans += str[i];
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}