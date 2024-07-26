#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

double n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    cout << fixed; cout.precision(2);
    cout << n / 4;
}

int main()
{
    INPUT();
    solution();
}