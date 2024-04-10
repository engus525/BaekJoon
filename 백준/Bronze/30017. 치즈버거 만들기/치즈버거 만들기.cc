#include <iostream>
#include <map>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void solution()
{
    if (a > b) cout << 2 * b + 1;
    else cout << 2 * a - 1;
}

int main()
{
    INPUT();
    solution();
}