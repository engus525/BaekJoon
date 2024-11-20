#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <thread>

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

int gcd(int a, int b)
{
    if (b == 0) return a;
    if (a < b) swap(a, b);
    return gcd(b, a % b);
}

void solution()
{
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << c / gcd(a, b) << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}