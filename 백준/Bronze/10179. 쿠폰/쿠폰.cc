#include <iostream>
#include <map>
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
    cout << fixed; cout.precision(2);
    while (t--)
    {
        double val; cin >> val;
        cout << "$" << val * 0.8 << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}