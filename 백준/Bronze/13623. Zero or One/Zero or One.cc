#include <iostream>
#include <math.h>
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
    if (a != b && b == c) cout << "A";
    else if (a != b && a == c) cout << "B";
    else if (a != c && a == b) cout << "C";
    else if (a != c && b == c) cout << "A";
    else if (b != c && a == b) cout << "C";
    else if (b != c && a == c) cout << "B";
    else cout << "*";
}

int main()
{
    INPUT();
    solution();
}