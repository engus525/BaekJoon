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

int GCD(int a, int b)
{
    while (b)
    {
        int mod = a % b;
        a = b;
        b = mod;
    }
    return a;
}

void solution()
{
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        while (a > 1)
        {
            // de >= (a/b) 만족
            int de = b / a + 1;
            a = a * de - b;
            b *= de;

            int gcd = GCD(a, b);
            a /= gcd, b /= gcd;
        }
        cout << b << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}