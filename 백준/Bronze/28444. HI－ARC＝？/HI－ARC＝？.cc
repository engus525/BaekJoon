#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c, d, e;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c >> d >> e;
}

void solution()
{
    cout << a * b - c * d * e;
}

int main()
{
    INPUT();
    solution();
}