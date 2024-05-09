#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

double a, b, c, d;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c >> d;
}

void solution()
{
    double A = a / b;
    double B = M_PI * c * c / d;
    if (A > B) cout << "Slice of pizza";
    else cout << "Whole pizza";
}

int main()
{
    INPUT();
    solution();
}