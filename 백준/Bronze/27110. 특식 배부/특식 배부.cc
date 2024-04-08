#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int a, b, c;

void INPUT()
{
    IAMFAST
    cin >> n >> a >> b >> c;
}

void solution()
{
    cout << min(n, a) + min(n, b) + min(n, c);
}

int main()
{
    INPUT();
    solution();
}