#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c;
}


void solution()
{
    if (a < b) cout << b;
    else if (b <= a && a <= c) cout << a;
    else cout << c;
}

int main()
{
    INPUT();
    solution();
}