#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
double value;
string unit;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    while (n--)
    {
        cin >> value >> unit;

        cout << fixed; cout.precision(4);
        if (unit == "kg") cout << value * 2.2046 << " lb";
        else if (unit == "lb") cout << value * 0.4536 << " kg";
        else if (unit == "l") cout << value * 0.2642 << " g";
        else if (unit == "g") cout << value * 3.7854 << " l";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}